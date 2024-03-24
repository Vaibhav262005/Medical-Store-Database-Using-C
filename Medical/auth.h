// auth.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authenticate.h"
#include "login.h"
#include "user.h"

#define MAX_LENGTH 100

struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char role[MAX_LENGTH];
};

void auth(){

    struct User users[MAX_LENGTH];
    int numUsers = 0;
    int option;

        printf("\n\n1- Login as User\n");
        printf("2- Login as Admin\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 2:
                login();
                break;

            case 1:
				authenticate();
				user();
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    
}

