#include <stdio.h>
#include "declaration.h"
#include "defines_1.h"
#include "passenger_struct.h"

void reserve_ticket()
{
    struct passenger_info *head = NULL;
    struct passenger_info *new;

    int train_number;
    char journey_date[20];

    int no_of_seats;
    int available_seats;
    int book_seats;
    int current_seat;

    char name[50];
    int age;
    char gender[10];

    int i;

    printf("\nRESERVE TICKET\n");

    display_trains();

    printf("\nEnter Train Number: ");
    scanf("%d", &train_number);

    printf("Enter Date of Journey: ");
    scanf("%s", journey_date);

    printf("Enter No. of Seats to Reserve: ");
    scanf("%d", &no_of_seats);

    if(no_of_seats <= 0)
    {
        printf("Invalid number of seats\n");
        return;
    }

    available_seats = get_available_seats(train_number);

    if(available_seats < 0)
    {
        printf("Invalid Train Number\n");
        return;
    }

    if(available_seats == 0)
    {
        printf("ERROR: No seats are available\n");
        return;
    }

    if(no_of_seats > available_seats)
    {
        book_seats = available_seats;

        printf("\nOnly %d seats are available\n",
               available_seats);

        printf("Only %d passengers can be booked\n",
               book_seats);
    }
    else
    {
        book_seats = no_of_seats;
    }

    current_seat = get_current_seat(train_number);

    if(current_seat < 0)
    {
        printf("Unable to get seat information\n");
        return;
    }

    for(i = 1; i <= book_seats; i++)
    {
        printf("\nPassenger %d\n", i);

        printf("Enter Name: ");
        scanf("%s", name);

        printf("Enter Age: ");
        scanf("%d", &age);

        printf("Enter Gender (Male/Female): ");
        scanf("%s", gender);

        current_seat++;

        new = create_node(train_number,
                          journey_date,
                          current_seat,
                          name,
                          age,
                          gender);

        if(new == NULL)
        {
            printf("Memory allocation failed\n");

            free_list(head);

            return;
        }

        insert_last(&head, new);

        save(new);

        printf("Seat Number: %d\n",
               current_seat);
    }

    update_seat_file(train_number,
                     book_seats);

    printf("\n%d ticket(s) reserved successfully\n",
           book_seats);

    if(no_of_seats > available_seats)
    {
        printf("ERROR: %d seat(s) could not be reserved\n",
               no_of_seats - available_seats);
    }

    free_list(head);
}
