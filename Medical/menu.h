// menu.h

 #include "auth.h"

void menu() {
    int op;
    printf("\n\n");
    printf("\t\t\t\t\t OPTIONS\n ");
    printf("\t\t-----------------------------------------------------------\n");

    printf("\n\n1-            LOGIN  \n");
    printf("\n\n2-            ABOUT  \n");
    printf("\n\n3-            EXIT \n\n");

    printf("ENTER YOUR CHOICE\n");
    scanf("%d", &op);
    printf("\t\t------------------------------------------------------\n\n");

    switch (op) {
    case 1:
        auth();
        break;

     case 2:
         printf(" SHREYA GARG \n BRANCH : CSE \n SECTION : C \n ROLL NO. : 23 \n");
         break;

     case 3:
         exit(0);
        break;
    }
}

