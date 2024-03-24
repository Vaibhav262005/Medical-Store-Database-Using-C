// login.h

 #include "meds.h"


void login() {
    struct meds *head = NULL;
    head = start();
    int num, id;
    char name[50], company[50];
    int masterpassword;
    printf("\t\t\t\t\t LOGIN\n ");
    printf("\t------------------------------------------------------------------\n");
    printf("ENTER THE MASTERPASSWORD TO ACCESS LOGIN\n");
    scanf("%d", &masterpassword);

    if (masterpassword == 1234) {
    	while(1){
        printf("\n\n\t\t\t\t**WELCOME**\n\n\n");
        printf("              OPTIONS    ");
        printf("               DESCRIPTION  \n");
        printf("\t------------------------------------------------------------------\n");
        printf("\n\n1-             ADD MEDICINE  ");
        printf("              ADDING NEW MEDICINE ");

        printf("\n\n2-            DELETE MEDICINE  ");
        printf("              TO DELETE A EXISTING MEDICINE ");

        printf("\n\n3-            DISPLAY ALL MEDICINES  ");
        printf("              DISPLAY ALL MEDICINES ");

        printf("\n\n4-            ISSUE MEDICINE ");
        printf("              TO ISSUE A MEDICINE ");

        printf("\n\n5-            RETURN MEDICINE ");
        printf("              TO RETURN A MEDICINE ");
        
        printf("\n\n6-            SEARCH MEDICINE ");
        printf("              TO SEARCH A MEDICINE BY NAME ");

        printf("\n\n7-            EXIT \n\n");

        printf("YOUR CHOICE\n");
        scanf("%d", &num);
        switch (num) {
        case 1:
            printf("Enter medicine ID to add: ");
            scanf("%d", &id);
            printf("Enter name of medicine to add: ");
            scanf("%s", name);
            printf("Enter company of medicine to add : ");
            scanf("%s", company);
            insertmeds(&head, id, name, company);
            break;
         case 2:
             printf("Enter medicine ID to delete: ");
             scanf("%d", &id);
             deletemeds(&head, id);
             break;
         case 3:
             displaymeds(head);
             break;
         case 4:
         	 printf("Enter the id of medicine to issue : ");
         	 scanf("%d", &id);
			 head = issuemeds(head,id);
             break;
         case 5:
             printf("Enter the id of medicine to return : ");
         	 scanf("%d", &id);
             returnmeds(head,id);
             break;
         case 6:
             printf("Enter the name of medicine to search : ");
         	 scanf("%s", name);
             struct meds *searchResult = (struct meds*)malloc(sizeof(struct meds));
             searchResult = searchmedsByName(head, name);
			 displaymeds(searchResult);
			
			
			while (searchResult != NULL) {
			    struct meds *temp = searchResult;
			    searchResult = searchResult->next;
			    free(temp);
			}
             break;
        case 7:
        	exit(0);
         default:
             printf("Invalid choice. Please enter a valid option.\n");
        }
    }}

}

