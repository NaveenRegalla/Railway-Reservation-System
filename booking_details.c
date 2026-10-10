#include <stdio.h>
#include "passenger_struct.h"

void booking_details(struct passenger_info *head)
{
    struct passenger_info *temp;

    temp = head;

    if(temp == NULL)
    {
        printf("\nNo booking details available\n");
        return;
    }

    printf("\nBOOKING DETAILS\n");

    printf("----------------------------------------------------------------------------\n");

    printf("%-12s %-15s %-10s %-20s %-8s %-10s\n",
           "Train No",
           "Journey Date",
           "Seat No",
           "Name",
           "Age",
           "Gender");

    printf("----------------------------------------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%-12d %-15s %-10d %-20s %-8d %-10s\n",
               temp->train_number,
               temp->journey_date,
               temp->seat_number,
               temp->name,
               temp->age,
               temp->gender);

        temp = temp->next;
    }

    printf("----------------------------------------------------------------------------\n");
}
