#include <stdio.h>
#include "defines.h"
#include "defines_1.h"
#include "passenger_struct.h"

void cancel_ticket()
{
    struct passenger_info *head;
    struct passenger_info *passenger;

    int train_number;
    char journey_date[20];
    int seat_number;

    printf("\nCANCEL TICKET\n");

    printf("Enter Train Number: ");
    scanf("%d", &train_number);

    printf("Enter Date of Journey: ");
    scanf("%s", journey_date);

    printf("Enter Seat Number to Cancel: ");
    scanf("%d", &seat_number);

    head = load_passengers();

    if(head == NULL)
    {
        printf("No passenger bookings available\n");
        return;
    }

    passenger = search_passenger(head,
                                 train_number,
                                 journey_date,
                                 seat_number);

    if(passenger == NULL)
    {
        printf("ERROR: Ticket not found\n");

        free_list(head);
        return;
    }

    delete_node(&head, train_number, journey_date, seat_number);

    syncfile(head);

    update_seat_file(train_number, -1);

    printf("\nTicket cancelled successfully\n");

    printf("Train Number : %d\n", train_number);
    printf("Journey Date : %s\n", journey_date);
    printf("Seat Number  : %d\n", seat_number);

    free_list(head);
}
