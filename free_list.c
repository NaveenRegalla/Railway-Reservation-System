#include <stdlib.h>
#include "passenger_struct.h"

void free_list(struct passenger_info *head)
{
    struct passenger_info *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }
}
