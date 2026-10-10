#ifndef PASSENGER_STRUCT_H
#define PASSENGER_STRUCT_H

struct passenger_info
{
    int train_number;
    char journey_date[20];
    int seat_number;
    char name[50];
    int age;
    char gender[10];

    struct passenger_info *next;
};

#endif
