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
    struct Node* temp = head;

    getCurrentDate(&currentDate);

    while(temp) {
        int result = getDifference(currentDate, temp->date);
        printf("svar: %d ", result);
       if(result > 21) {
           free(temp);
       } 
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