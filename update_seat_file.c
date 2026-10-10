#include <stdio.h>
#include "seat_struct.h"
#include "defines.h"

void update_seat_file(int train_number, int booked_seats)
{
    FILE *fp;
    FILE *temp_fp;

    struct seats_info s;

    fp = fopen("data/seats_info_data.txt", "r");

    if(fp == NULL)
    {
        printf("Seat file opening failed\n");
        return;
    }

    temp_fp = fopen("data/temp_seats.txt", "w");

    if(temp_fp == NULL)
    {
        printf("Temporary file opening failed\n");
        fclose(fp);
        return;
    }

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
        if(s.train_number == train_number)
        {
            s.current_booking_seat_number += booked_seats;
        }

        fprintf(temp_fp,
                "Train Number                 : %d\n"
                "Total Seats                  : %d\n"
                "Waiting List                 : %d\n"
                "Current Booking Seat Number  : %d\n\n",
                s.train_number,
                s.total_seats,
                s.waiting_list,
                s.current_booking_seat_number);
    }

    fclose(fp);
    fclose(temp_fp);

    remove("data/seats_info_data.txt");
    rename("data/temp_seats.txt", "data/seats_info_data.txt");
}
