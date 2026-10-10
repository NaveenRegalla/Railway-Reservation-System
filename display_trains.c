#include <stdio.h>
#include "train_struct.h"

void display_trains()
{
    FILE *fp;
    struct train_info t;

    fp = fopen("data/trains_info_data.txt", "r");

    if(fp == NULL)
    {
        printf("Train file not found\n");
        return;
    }

    printf("\nAVAILABLE TRAINS\n");

    printf("-------------------------------------------------------------\n");
    printf("%-15s %-30s %-25s %-25s\n",
           "Train Number",
           "Train Name",
           "Source",
           "Destination");

    printf("-------------------------------------------------------------\n");

    while(fscanf(fp,
                 "Train Name    : %[^\n]\n"
                 "Train Number  : %d\n"
                 "Source        : %[^\n]\n"
                 "Destination   : %[^\n]\n"
                 "No. of Seats  : %*d\n\n",
                 t.train_name,
                 &t.train_number,
                 t.source,
                 t.destination) == 4)
    {
        printf("%-15d %-30s %-25s %-25s\n",
               t.train_number,
               t.train_name,
               t.source,
               t.destination);
    }

    printf("-------------------------------------------------------------\n");

    fclose(fp);
}
