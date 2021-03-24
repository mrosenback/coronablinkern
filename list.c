#include "list.h"
#include "date.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Date date;
    struct Node *next;
};

struct Node *head;

CurrentDate currentDate;

bool insert(int value, int dd, int mm, int yy)
{
    struct Node *new_node, *node;
    new_node = malloc(sizeof(struct Node));

    new_node->data = value;
    new_node->date.day = dd;
    new_node->date.month = mm;
    new_node->date.year = yy;
    new_node->next = NULL;

    if (head == NULL || isBefore(head->date, new_node->date))
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        node = head;
        while (node->next != NULL && isBefore(new_node->date, node->next->date))
        {
            node = node->next;
        }

        new_node->next = node->next;
        node->next = new_node;
    }

    return true;
}

bool delete ()
{
    struct Node *temp = head, *prev;

    getCurrentDate(&currentDate);
    int result = getDifference(currentDate, temp->date);

    if (result > 21 && temp != NULL)
    {
        head = temp->next;
        free(temp);
    }

    while (temp != NULL)
    {
        result = getDifference(currentDate, temp->date);

        if (result > 21)
        {
            prev->next = temp->next;
            free(temp);
        }
        prev = temp;
        temp = temp->next;
    }

    return true;
}

bool printList()
{
    struct Node *node = head;

    printf("\n+--------+-----------------+");
    while (node != NULL)
    {
        printf("\n| ID: %d | Date: %d/%d/%d |\n", node->data, node->date.day, node->date.month, node->date.year);
        printf("+--------+-----------------+");
        node = node->next;
    }
    printf("\n");

    return true;
}

bool writeToFile(FILE *fileptr)
{
    struct Node *node = head;

    while (node != NULL)
    {
        fwrite(&node->data, sizeof(int), 1, fileptr);
        fwrite(&node->date.day, sizeof(int), 1, fileptr);
        fwrite(&node->date.month, sizeof(int), 1, fileptr);
        fwrite(&node->date.year, sizeof(int), 1, fileptr);

        node = node->next;
    }

    return true;
}

bool readFromFile(FILE *fileptr)
{
    struct Node *node = malloc(sizeof(struct Node));

    while (fread(&node->data, sizeof(int), 1, fileptr) == 1)
    {
        fread(&node->date.day, sizeof(int), 1, fileptr);
        fread(&node->date.month, sizeof(int), 1, fileptr);
        fread(&node->date.year, sizeof(int), 1, fileptr);

        insert(node->data, node->date.day, node->date.month, node->date.year);
    }

    return true;
}

bool checkContagion(int code)
{
    struct Node *node = head;
    bool safe = false;

    while (node != NULL)
    {
        if (code == node->data)
        {
            printf("\nYou may have been exposed by ID: %d\n", code);
            safe = true;
            break;
        }
        node = node->next;
    }

    if (!safe)
    {
        printf("\nYou are safe!\n");
    }

    return true;
}