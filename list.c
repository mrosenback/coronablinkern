#include "list.h"
#include "date.h"
#include <stdio.h>
#include <stdlib.h>

struct Node { 
    int data;
    Date date;
    struct Node* next; 
};

struct Node* head;

CurrentDate currentDate;

bool insert(int value, int dd, int mm, int yy) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->date.day = dd;
    temp->date.month = mm;
    temp->date.year = yy;
    temp->next = NULL;

    if(head != NULL) {
        temp->next = head;
    }

    head = temp;

    return true;
}

bool delete() {
    struct Node* temp = head, *prev;

    getCurrentDate(&currentDate);

    while(temp != NULL) {
        int result = getDifference(currentDate, temp->date);

       if(result > 21 && temp != NULL) {
           head = temp->next;
           free(temp);
       } else if(result > 21) {
           prev->next = temp->next;
           free(temp);
       } 
       prev = temp;
       temp = temp->next;
    }

    return true;
}

bool printList() {
    struct Node* temp = head;

    printf("\n----------------------------");
    while(temp != NULL) {
        printf("\n| ID: %d | Date: %d/%d/%d |\n",temp->data, temp->date.day, temp->date.month, temp->date.year);
        printf("----------------------------");
        temp = temp->next;
    }
    printf("\n");

    return true;
}

bool writeToFile(FILE * fileptr) {
    struct Node* temp = head;
    
    while(temp != NULL) {
        fprintf(fileptr,"\n| ID: %d | Date: %d/%d/%d |\n",temp->data, temp->date.day, temp->date.month, temp->date.year);
        temp = temp->next;
    }
    
    return true;
}

bool readFromFile(FILE * fileptr) {
    int value, dd, mm, yy;
    int fieldsRead;

    do {
        fieldsRead = fscanf(fileptr,"\n| ID: %d | Date: %d/%d/%d |\n",&value, &dd, &mm, &yy);

        if(fieldsRead == 4) {
            insert(value, dd, mm, yy);
        }
    } while(fieldsRead == 4);
    
    return true;
}

bool checkContagion(int code) {
    struct Node* temp = head;
    bool safe = false;
    
    while(temp != NULL) {
        if(code == temp->data) {
            printf("\nYou may have been exposed by ID: %d\n", code);
            safe = true;
            break;
        }
        temp = temp->next;
    }

    if(!safe) {
        printf("\nYou are safe!\n");
    }

    return true;
}