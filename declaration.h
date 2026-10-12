#ifndef DEFINES_H
#define DEFINES_H

void signup();
int signin();

void menu2();

/* Train */
void display_trains();

/* Seats */
void display_seats();
int get_available_seats(int train_number);
int get_current_seat(int train_number);
void update_seat_file(int train_number, int booked_seats);

#endif
