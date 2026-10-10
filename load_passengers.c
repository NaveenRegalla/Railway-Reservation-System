#include <stdio.h>
#include <stdlib.h>
#include "passenger_struct.h"

struct passenger_info *load_passengers()
{
    FILE *fp;

    struct passenger_info *head = NULL;
    struct passenger_info *new;
    struct passenger_info *temp;

    fp = fopen("passengers.txt", "r");

    if(fp == NULL)
    {
        return NULL;
    }

    while(1)
    {
        new = malloc(sizeof(struct passenger_info));

        if(new == NULL)
        {
            fclose(fp);
            return head;
        }

        if(fscanf(fp,
                  "Train Number  : %d\n"
                  "Journey Date  : %19[^\n]\n"
                  "Seat Number   : %d\n"
                  "Name          : %49[^\n]\n"
                  "Age           : %d\n"
                  "Gender        : %9[^\n]\n\n",
                  &new->train_number,
                  new->journey_date,
                  &new->seat_number,
                  new->name,
                  &new->age,
                  new->gender) != 6)
        {
            free(new);
            break;
        }

        new->next = NULL;

        if(head == NULL)
        {
            head = new;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = new;
        }
    }

    fclose(fp);

    return head;
}
