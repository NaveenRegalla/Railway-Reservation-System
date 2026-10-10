#include <stdio.h>
#include "defines.h"
#include "seat_struct.h"

int get_available_seats(int train_number)
{
    FILE *fp;
    struct seats_info s;

    fp = fopen("data/seats_info_data.txt", "r");

    if(fp == NULL)
    {
        printf("Seat file opening failed\n");
        return -1;
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
            fclose(fp);

            return s.total_seats -
                   s.current_booking_seat_number;
        }
    }

    fclose(fp);

    return -1;
}
