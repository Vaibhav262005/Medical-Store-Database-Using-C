//authenticate.h

void authenticate()
{
    char password[20]; 
    
    printf("Enter password\n");
    scanf("%s", password);

    
    if(strcmp(password, "pass1234") == 0)
    {
        printf("Authenticated successfully\n");
    }
    else
    {
        printf("WRONG PASSWORD!!! TRY AGAIN\n");
        exit(0);
    }
}
