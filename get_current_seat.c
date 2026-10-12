#include <stdio.h>
#include "seat_struct.h"
#include "declaration.h"

int get_current_seat(int train_number)
{
    FILE *fp;
    struct seats_info s;

    fp = fopen("data/seats_info_data.txt", "r");

    if(fp == NULL)
    {
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

            return s.current_booking_seat_number;
        }
    }

    fclose(fp);

    return -1;
}
