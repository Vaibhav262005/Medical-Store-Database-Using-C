// user.c

#include <stdio.h>
#include <stdlib.h>

struct meds *initial(){
    struct meds *ptr,*med1,*med2,*med3;

    med1=(struct meds *)malloc(sizeof(struct meds));
    med1->next=NULL;
    strcpy(med1->name,"Crocin");
    strcpy(med1->company,"abcd");
    med1->medID=101;
    med1->isIssued=0;
    ptr=med1;

    med2=(struct meds*)malloc(sizeof(struct meds));
    med2->next=NULL;
    strcpy(med2->name,"Paracetamol");
    strcpy(med2->company,"klmn");
    med2->medID=102;
    med2->isIssued=0;
    ptr->next=med2;
    ptr=med2;
    
    med3=(struct meds *)malloc(sizeof(struct meds));
    med3->next=NULL;
    strcpy(med3->name,"AstaForex");
    strcpy(med3->company,"vbnm");
    med3->medID=103;
    med3->isIssued=0;
    ptr->next=med3;
    ptr=med3;

    return med1;
}

void Displaymeds(struct meds *head) {
    struct meds *current = head;

    while (current != NULL) {
        printf("Medicine ID: %d, Name: %s, Company: %s, Issued: %d\n",
               current->medID, current->name, current->company, current->isIssued);
        current = current->next;
    }
}
void displayAvailableMeds(struct meds *head) {
    printf("\nAvailable Medicines:\n");
    Displaymeds(head);
}


void Issuemeds(struct meds *head, int medicineID) {
    struct meds *current = head;

    while (current != NULL) {
        if (current->medID == medicineID) {
            if (current->isIssued == 0) {
                current->isIssued = 1;
                printf("Medicine '%d' issued successfully.\n", medicineID);
            } else {
                printf("Medicine '%d' is already issued.\n", medicineID);
            }
            return;
        }
        current = current->next;
    }

    printf("Medicine '%d' not found.\n", medicineID);
}
void issueMedicine(struct meds *head) {
    int id;
    printf("Enter the id of the medicine to issue: ");
    scanf("%d", &id);

    Issuemeds(head, id);
}


void Returnmeds(struct meds *head, int medicineID) {
    struct meds *current = head;

    while (current != NULL) {
        if (current->medID == medicineID) {
            if (current->isIssued == 1) {
                current->isIssued = 0;
                printf("Medicine '%d' returned successfully.\n", medicineID);
            } else {
                printf("Medicine '%d' is not issued.\n", medicineID);
            }
            return;
        }
        current = current->next;
    }

    printf("Medicine '%d' not found.\n", medicineID);
}
void returnMedicine(struct meds *head) {
    int id;
    printf("Enter the id of the medicine to return: ");
    scanf("%d", &id);

    Returnmeds(head, id);
}

void user() {
    
    struct meds *head = NULL;
    head = initial();


    int option;

    do {
        printf("\n\n1- Display Available Medicines\n");
        printf("2- Issue Medicine\n");
        printf("3- Return Medicine\n");
        printf("4- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayAvailableMeds(head);
                break;

            case 2:
                issueMedicine(head);
                break;

            case 3:
                returnMedicine(head);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } while (option != 4);
}

