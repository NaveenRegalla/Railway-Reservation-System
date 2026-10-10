#include <stdio.h>
#include "defines_1.h"
#include "passenger_struct.h"

void syncfile(struct passenger_info *head)
{
    FILE *fp;
    struct passenger_info *temp;

    fp = fopen("passengers.txt", "w");

    if(fp == NULL)
    {
        printf("Passenger file opening failed\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "Train Number  : %d\n", temp->train_number);
        fprintf(fp, "Journey Date  : %s\n", temp->journey_date);
        fprintf(fp, "Seat Number   : %d\n", temp->seat_number);
        fprintf(fp, "Name          : %s\n", temp->name);
        fprintf(fp, "Age           : %d\n", temp->age);
        fprintf(fp, "Gender        : %s\n\n", temp->gender);

        temp = temp->next;
    }

    fclose(fp);
}
