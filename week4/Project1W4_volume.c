// Modifies the volume of an audio file
// This copies a WAV file, changes the vol, outputs a copy
// arg 1; file input, arg 2; file output, arg 3; volume factor
// read and write header 44-byte
// samples are 2 bytes

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav vol factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb"); // reads input file
    if (input == NULL)                  // check for NULL ptr after every ptr
    {
        printf("Could not open file.\n");
        fclose(input);
        return 1;
    }

    FILE *output = fopen(argv[2], "wb"); // writes input file
    if (output == NULL)                  // check for NULL ptr after every ptr
    {
        printf("Could not open file.\n");
        fclose(output); // good practice ma boi
        return 1;
    }

    float factor = atof(argv[3]); // converts a string to a float

    // HEADER
    // create space for the header
    uint8_t *header_container = malloc(44);
    if (header_container == NULL)
    {
        printf("Could not allocate memory");
        fclose(input);
        fclose(output);
        return 1;
    }
    // read the input file
    fread(header_container, sizeof(uint8_t), 44, input);

    // copy the header to output file
    fwrite(header_container, sizeof(uint8_t), 44, output);
    free(header_container); // free header memory

    // SAMPLES
    // get the size of the file to find how many samples
    fseek(input, 0, SEEK_END);     // moves input to the end
    long file_size = ftell(input); // gets total bytes
    int sample_units = (file_size - 44) / 2;

    // dynamically allocate memory for the samples
    int16_t *samples_container = malloc(sample_units * sizeof(int16_t));
    if (samples_container == NULL)
    {
        printf("Could not allocate memory");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Reset file pointer & read the input file
    fseek(input, 44, SEEK_SET);
    fread(samples_container, sizeof(int16_t), sample_units, input);

    // multiply each element by factor
    for (int i = 0; i < sample_units; i++)
    {
        int value_buffer = samples_container[i] * factor;
        if (value_buffer > INT16_MAX)
            value_buffer = INT16_MAX;
        else if (value_buffer < INT16_MIN)
            value_buffer = INT16_MIN;
        samples_container[i] = (int16_t) value_buffer;
    }

    // No need to move pointer on output
    // copy samples to output file
    fwrite(samples_container, sizeof(int16_t), sample_units, output);

    // free memory
    free(samples_container);

    // Close files
    fclose(input);
    fclose(output);
}
