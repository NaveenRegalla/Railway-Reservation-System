#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "user_struct.h"

void signup()
{
    FILE *fp;
    struct user u;

    char username[50];
    char password[50];

    int i;
    int upper, lower, digit, special;
    int attempts;
    int found;

    /* USERNAME */
    while(1)
    {
        found = 0;

        printf("Enter username: ");
        scanf("%s", username);

        fp = fopen("usr_logins.txt", "r");

        if(fp != NULL)
        {
            while(fscanf(fp, "%s %s", u.username, u.password) == 2)
            {
                if(strcmp(username, u.username) == 0)
                {
                    found = 1;
                    break;
                }
            }

            fclose(fp);
        }

        if(found == 0)
        {
            break;
        }

        printf("ERROR: Username already exists\n");
        printf("Please enter another username\n");
    }

    /* PASSWORD */
    attempts = 0;

    while(attempts < 5)
    {
        printf("Enter password: ");
        scanf("%s", password);

        upper = 0;
        lower = 0;
        digit = 0;
        special = 0;

        if(strlen(password) < 8)
        {
            printf("ERROR: Password must be minimum 8 characters\n");
            attempts++;
            continue;
        }

        for(i = 0; password[i] != '\0'; i++)
        {
            if(isupper(password[i]))
            {
                upper = 1;
            }
            else if(islower(password[i]))
            {
                lower = 1;
            }
            else if(isdigit(password[i]))
            {
                digit = 1;
            }
            else
            {
                special = 1;
            }
        }

        if(upper == 1 && lower == 1 &&
           digit == 1 && special == 1)
        {
            break;
        }

        printf("ERROR: Password must contain:\n");

        if(upper == 0)
            printf("- At least one uppercase character\n");

        if(lower == 0)
            printf("- At least one lowercase character\n");

        if(digit == 0)
            printf("- At least one numeric character\n");

        if(special == 0)
            printf("- At least one special character\n");

        attempts++;
    }

    if(attempts == 5)
    {
        printf("\nTIME OUT\n");
        printf("Please sign-up again\n");
        return;
    }

    /* STORE USERNAME AND PASSWORD */
    fp = fopen("usr_logins.txt", "a");

    if(fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);

    printf("Sign-up successful\n");
}
