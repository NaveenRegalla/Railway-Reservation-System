#include<stddef.h>
#include "passenger_struct.h"

void insert_last(struct passenger_info **head,
                 struct passenger_info *new)
{
    struct passenger_info *temp;

    if(*head == NULL)
    {
        *head = new;
        return;
    }

    temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
}
