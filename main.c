#include <stdio.h>

#include "declaration.h"
#include "defines_1.h"

int main()
{
    int choice;

    printf("MENU-1\n");
    printf("1. Sign-up\n");
    printf("2. Sign-in\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            signup();
            break;

        case 2:
            if(signin())
            {
                menu2();
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

void menu2()
{
    char choice;

    struct passenger_info *head;

    while(1)
    {
        printf("\nMENU-2\n");
        printf("R/r : Reserve Ticket\n");
        printf("C/c : Cancel Ticket\n");
        printf("B/b : Booking Details\n");
        printf("Q/q : Quit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'R':
            case 'r':
                reserve_ticket();
                break;

            case 'C':
            case 'c':
                cancel_ticket();
                break;

            case 'B':
            case 'b':

                head = load_passengers();

                booking_details(head);

                free_list(head);

                break;

            case 'Q':
            case 'q':
                printf("Thank you\n");
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}
