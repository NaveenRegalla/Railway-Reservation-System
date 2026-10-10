#include <stdio.h>
#include <string.h>
#include "user_struct.h"

int signin()
{
    FILE *fp;
    struct user u;

    char username[50];
    char password[50];

    int attempts;

    for(attempts = 1; attempts <= 3; attempts++)
    {
        printf("Enter USR_NAME: ");
        scanf("%s", username);

        printf("Enter PASSWORD: ");
        scanf("%s", password);

        fp = fopen("usr_logins.txt", "r");

        if(fp == NULL)
        {
            printf("File opening failed\n");
            return 0;
        }

        while(fscanf(fp, "%s %s",
                     u.username,
                     u.password) == 2)
        {
            if(strcmp(username, u.username) == 0 &&
               strcmp(password, u.password) == 0)
            {
                fclose(fp);

                printf("LOGIN SUCCESSFUL\n");

                return 1;
            }
        }

        fclose(fp);

        printf("Invalid username or password\n");
    }

    printf("\nYou have reached max no. of attempts,\n");
    printf("please wait for 5 mins to login again.\n");

    return 0;
}
