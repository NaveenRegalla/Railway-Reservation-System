#include <stddef.h>
#include <string.h>
#include "defines_1.h"
#include "passenger_struct.h"

struct passenger_info *search_passenger(
    struct passenger_info *head,
    int train_number,
    char journey_date[],
    int seat_number)
{
    struct passenger_info *temp;

    temp = head;

    while(temp != NULL)
    {
        if(temp->train_number == train_number &&
           strcmp(temp->journey_date, journey_date) == 0 &&
           temp->seat_number == seat_number)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}
