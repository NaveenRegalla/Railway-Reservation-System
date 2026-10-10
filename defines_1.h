#ifndef DEFINES1_H
#define DEFINES1_H

struct passenger_info;

void cancel_ticket();

void reserve_ticket();

void booking_details(struct passenger_info *head);

struct passenger_info *load_passengers();

struct passenger_info *search_passenger(
    struct passenger_info *head,
    int train_number,
    char journey_date[],
    int seat_number
);

void delete_node(
    struct passenger_info **head,
    int train_number,
    char journey_date[],
    int seat_number);

void syncfile(struct passenger_info *head);

void free_list(struct passenger_info *head);

struct passenger_info *create_node(
    int train_number,
    char journey_date[],
    int seat_number,
    char name[],
    int age,
    char gender[]
);

void insert_last(
    struct passenger_info **head,
    struct passenger_info *new
);

void save(struct passenger_info *new);

#endif
