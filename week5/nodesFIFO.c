// linked list FIFO

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(void)
{
    // linked list header
    node *list = NULL;
    int nodenum = get_int("How many values: \n");

    // linked list tail
    node *tail = NULL;

    // node *temp = NULL;
    // temp = malloc(sizeof(node));
    // if (temp == NULL)
    // {
    //     printf("memory error");
    //     return 1;
    // }
    // temp->number = get_int("Number: ");
    // temp->next = NULL;

    // list = temp;
    // tail = temp;


    // create tail nodes
    for(int i = 0; i < nodenum; i++)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("memory error");
            return 1;
        }
        temp->number = get_int("Number: ");
        temp->next = NULL;

        if (list == NULL)
        {
            list = temp;
            tail = temp;
        }
        else
        {
        tail->next = temp;
        tail = temp;
        }

    }

    // print node values
    // ptr points to the header
    node *ptr = list;

    while(ptr != NULL)
    {
        printf("%i \n", ptr->number);
        ptr = ptr->next;
    }
    free(list);
    free(tail);
    return 0;
}
