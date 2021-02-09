#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "date.h"

struct Node { 
    int data;
    Date date;
    struct Node* next; 
};

struct Node* head;

//Insert new identification code and date to list
void insert(int value, int dd, int mm, int yy) {

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->date.day = dd;
    temp->date.month = mm;
    temp->date.year = yy;
    temp->next = NULL;

    if(head != NULL) {
        temp->next = head;
    }

    head = temp;
}

//Print the list
void printList() {

    struct Node* temp = head;
    
    printf("\n-----");
    while(temp != NULL) {
        printf("\nIdentification code: %d Date: %d/%d/%d\n",temp->data, temp->date.day, temp->date.month, temp->date.year);
        printf("-----");
        temp = temp->next;
    }
    printf("\n");
}