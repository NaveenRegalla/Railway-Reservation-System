#include <stdio.h>
#include "seat_struct.h"
#include "declaration.h"

void display_seats()
{
    FILE *fp;
    struct seats_info s;

    fp = fopen("data/seats_info_data.txt", "r");

    if(fp == NULL)
    {
        printf("Seat file not found\n");
        return;
    }

    printf("\nSEAT INFORMATION\n");

    printf("----------------------------------------------------------------\n");

    printf("%-15s %-15s %-15s %-20s\n",
           "Train Number",
           "Total Seats",
           "Waiting List",
           "Current Booking");

    printf("----------------------------------------------------------------\n");

    while(fscanf(fp,
                 "Train Number                 : %d\n"
                 "Total Seats                  : %d\n"
                 "Waiting List                 : %d\n"
                 "Current Booking Seat Number  : %d\n\n",
                 &s.train_number,
                 &s.total_seats,
                 &s.waiting_list,
                 &s.current_booking_seat_number) == 4)
    {
        printf("%-15d %-15d %-15d %-20d\n",
               s.train_number,
               s.total_seats,
               s.waiting_list,
               s.current_booking_seat_number);
    }

    printf("----------------------------------------------------------------\n");

    fclose(fp);
}
