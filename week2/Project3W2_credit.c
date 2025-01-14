// building a checksum program
// checks the validity of a credit card
// this program took mE WAY TOO LONG TO DEBUG EVRYTHING!!!

#include <cs50.h>
#include <stdio.h>

int check_num(long x);
bool check_sum(long x);
string cardbrand(long x, int y);


int main()
{
    printf("Hello! This program checks you credit card legitimacy\n");
    long cardnum = get_long("Number: ");

    // check how many digits in the card number
    int numofdigits = check_num(cardnum);

    // remove cards that are not a viable CC digit number
    if (!(numofdigits == 15 || numofdigits == 16 || numofdigits == 13))
    {
        printf("INVALID\n");
        return 0;
    }

    // check sum and remove cards that fail the luhn's test
    if (check_sum(cardnum) == false)
    {
        printf("INVALID\n");
        return 0;
    }

    // print out brand of card
    printf("%s", cardbrand(cardnum, numofdigits));
    return 0;
}

// check for number of digits in a cardnum
int check_num(long x)
{
    long n = x;
    int numofdigits = 0;
    do
    {
        n = (n)/10;
        numofdigits ++;
    }
    while (n != 0);
    return numofdigits;
}

// check if check sum is correct
bool check_sum(long x)
{
    long cardnum = x;

    // first sum
    int sum1 = 0;
    int sum1tot = 0;
    long temp1 = cardnum/10;
    do
    {
        sum1 = (temp1%10) * 2; //2nd number x 2 = sum1
        if (sum1 >= 10)
        {
            sum1tot += (sum1%10) + (sum1/10);
        }
        else
        {
            sum1tot += sum1;
        }
        temp1 = temp1/100; //skip 1 number
    }while (temp1 != 0);
    // printf("sum 1: %i\n", sum1tot);

    // second sum
    int sum2 = 0;
    do
    {
        sum2 += cardnum%10;
        cardnum = cardnum/100;
    }while (cardnum != 0);
    // printf("sum 2: %i\n", sum2);

    //total sum
    int total = sum1tot + sum2;
    // printf("total: %i\n", total);

    //modulo
    // printf("total modulo: %i\n", total%10);

    if (total%10 == 0)
    {
        return true;
    }
    return false;
}

// check brand of card
string cardbrand(long x, int y)
{
    long cardnum = x;
    int numofdigits = y;

    // calculate first digits at the level
    // since you can divide according to numofdigits


    if (numofdigits == 16)
    {
        // remove the last 14 digits
        for (int i = 0; i < 14; i++)
        {
            cardnum = cardnum/10;
        }

        // check for MASTERCARD numbers
        if (cardnum <= 55 && cardnum >= 51)
        {
            return "MASTERCARD\n";
        }
        else if (cardnum/10 == 4)
        {
            return "VISA\n";
        }
        else
        {
            return "INVALID\n";
        }

    }
    else if (numofdigits == 15)
    {
        // remove last 13 digits
        for (int i = 0; i < 13; i++)
        {
            cardnum = cardnum/10;
        }

        // check for AMEX numbers
        if (cardnum == 34 || cardnum == 37)
        {
            return "AMEX\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    else if (numofdigits == 13)
    {
        // remove last 12 digits
        for (int i = 0; i < 12; i++)
        {
            cardnum = cardnum/10;
        }

        // check for VISA numbers
        if (cardnum == 4)
        {
            return "VISA\n";
        }
        else
        {
            return "INVALID\n";
        }

    }
    return "INVALID\n";
}
