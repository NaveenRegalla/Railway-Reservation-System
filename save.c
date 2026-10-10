#include <stdio.h>
#include "passenger_struct.h"

void save(struct passenger_info *new)
{
    FILE *fp;

    fp = fopen("passengers.txt", "a");

    if(fp == NULL)
    {
        printf("Passenger file opening failed\n");
        return;
    }

    fprintf(fp, "Train Number  : %d\n", new->train_number);
    fprintf(fp, "Journey Date  : %s\n", new->journey_date);
    fprintf(fp, "Seat Number   : %d\n", new->seat_number);
    fprintf(fp, "Name          : %s\n", new->name);
    fprintf(fp, "Age           : %d\n", new->age);
    fprintf(fp, "Gender        : %s\n\n", new->gender);

    fclose(fp);
}
