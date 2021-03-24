#include "date.h"
#include "list.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

Date date;

//Simulates the network communication
void networkSimulation(int messageType) {
    if(messageType == 1) {
        printf("\n- Opening code received. Sending information to the server. -\n");

        for (int i = 0; i < 3; i++)
        {
            Sleep(1000);
            printf(".");
        }
        Sleep(1000);
        printf("\n- Information has succesfully been sent! -\n");
    } else {
        printf("- Information has been saved! -\n");
    }
    
    

    Sleep(1000);
}

//Shows the Opening Code menu
void openingCode() {
    int openingCode;

    printf("\n--- "ANSI_COLOR_RED"Opening Code"ANSI_COLOR_RESET" ---\n\n");
    printf("Enter your Opening Code: ");
    scanf("%d", &openingCode);

    delete();
    printList();
    networkSimulation(1);
}

//Shows the Identification Code menu
void identificationCode() {
    int id;
    int dd,mm,yy;
    
    printf("\n--- "ANSI_COLOR_RED"Identification Code"ANSI_COLOR_RESET" ---\n\n");
    printf("Enter the Identification Code: ");
    scanf("%d", &id);

    //Loops if the date is not valid
    while(1) {
        printf("Enter the date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &dd, &mm, &yy);

        printf("\n");

        setDate(&date, dd, mm, yy);
        
        if(!checkDate(date)) {
            continue;
        } else {
            break;
        }
    }
    insert(id, dd, mm, yy);
    networkSimulation(2);
}

//Shows if you've been exposed with random code
void contagionAlarm() {
    int code;

    printf("\n--- "ANSI_COLOR_RED"Contagion Alarm"ANSI_COLOR_RESET" ---\n");

    printf("Enter the ID: ");
    scanf("%d", &code);
    
    checkContagion(code);
    Sleep(2000);
}

int main() {
    int choice = 5;
    char * fileName = "list.bin";
    FILE * fileptr;

    fileptr = fopen(fileName, "rb");
    if(fileptr != NULL) {
        readFromFile(fileptr);
    }
    fclose(fileptr);
    
    //Loops until the the exit option is picked
    while (1)
    {
        printf("\n--- "ANSI_COLOR_RED"Welcome to Coronablinkern"ANSI_COLOR_RESET" ---\n\n");
        printf("1< Enter an Opening Code if you have been infected\n2< Enter Identification Code\n3< Receive Infection Alarm\n4< Exit\n\n");
        printf("Choose category (1, 2 or 3): ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            openingCode();
        } else if(choice == 2) {
            identificationCode();
        } else if(choice == 3) {
            contagionAlarm();
        } else if(choice == 4) {
            printf("\nExiting program. Goodbye!\n\n");
            break;
        } else {
            printf("\nError: Choose a valid category.\n");
            Sleep(2000);
        }
    }

    delete();

    fileptr = fopen(fileName, "wb");
    if(fileptr != NULL) {
        writeToFile(fileptr);
    } else {
        printf("File not found!");
    }
    fclose(fileptr);
    
    return 0;
}