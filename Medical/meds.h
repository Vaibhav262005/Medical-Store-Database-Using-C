// // meds.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct meds {
    int medID;
    char name[50];
    char company[50];
    int isIssued;
    struct meds *next;
};


struct meds *head = NULL;

struct meds *start(){
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

struct meds *createmeds(int medID, char name[], char company[]) {
    struct meds *newmeds = (struct meds *)malloc(sizeof(struct meds));

    if (newmeds == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in createmeds\n");
        exit(EXIT_FAILURE);
    }

    newmeds->medID = medID;

    if (strlen(name) < sizeof(newmeds->name)) {
        strcpy(newmeds->name, name);
    } else {
        fprintf(stderr, "Error: Name is too long in createmeds\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(company) < sizeof(newmeds->company)) {
        strcpy(newmeds->company, company);
    } else {
        fprintf(stderr, "Error: Company name is too long in createmeds\n");
        exit(EXIT_FAILURE);
    }

    newmeds->isIssued = 0;
    newmeds->next = NULL;

    return newmeds;
}



void insertmeds(struct meds **head, int medID, char name[], char company[]) {
    struct meds *newmeds = createmeds(medID, name, company);
    newmeds->next = *head;
    *head = newmeds;
    printf("Medicine added successfully.\n");
}

void deletemeds(struct meds **head, int medID) {
    struct meds *current = *head;
    struct meds *prev = NULL;

    while (current != NULL && current->medID != medID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Medicine not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Medicine removed successfully.\n");
}

void displaymeds(struct meds *head) {
    struct meds *current = head;

    while (current != NULL) {
        printf("Medicine ID: %d, Name: %s, Company: %s, Issued: %d\n",
               current->medID, current->name, current->company, current->isIssued);
        current = current->next;
    }
}

struct meds *issuemeds(struct meds *head, int medicineID) {
    struct meds *current = head;

    while (current != NULL) {
        if (current->medID == medicineID) {
            if (current->isIssued == 0) {
                current->isIssued = 1;
                printf("Medicine '%d' issued successfully.\n", medicineID);
            } else {
                printf("Medicine '%d' is already issued.\n", medicineID);
            }
            return head;
        }
        current = current->next;
    }

    printf("Medicine '%d' not found.\n", medicineID);
    return head;
}


void returnmeds(struct meds *head, int medicineID) {
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

struct meds *searchmedsByName(struct meds *head, char searchName[]) {

    struct meds *current = head;

    while (current != NULL) {
        if (strstr(current->name, searchName) != NULL) {
        	
        	printf("MedId = %d\n",current->medID);
        	printf("Medicine Name = %s\n",current->name);
        	printf("Medicine company = %s\n",current->company);
            
        }
        current = current->next;
    }

    return current;
}


