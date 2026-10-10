#include <stdlib.h>
#include <string.h>
#include "passenger_struct.h"

struct passenger_info *create_node(
    int train_number,
    char journey_date[],
    int seat_number,
    char name[],
    int age,
    char gender[])
{
    struct passenger_info *new;

    new = malloc(sizeof(struct passenger_info));

    if(new == NULL)
    {
        return NULL;
    }

    new->train_number = train_number;
    strcpy(new->journey_date, journey_date);
    new->seat_number = seat_number;
    strcpy(new->name, name);
    new->age = age;
    strcpy(new->gender, gender);

    new->next = NULL;

    return new;
}
