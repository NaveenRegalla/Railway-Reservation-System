#include <stdlib.h>
#include <string.h>
#include "passenger_struct.h"

void delete_node(
    struct passenger_info **head,
    int train_number,
    char journey_date[],
    int seat_number)
{
    struct passenger_info *temp;
    struct passenger_info *prev;

    temp = *head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->train_number == train_number &&
           strcmp(temp->journey_date, journey_date) == 0 &&
           temp->seat_number == seat_number)
        {
            if(prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}
