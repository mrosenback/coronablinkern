#include "date.h"
#include "list.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

    printf("\n--- Opening Code ---\n\n");
    printf("Enter your Opening Code: ");
    scanf("%d", &openingCode);

    printList();
    networkSimulation(1);
}

//Shows the Identification Code menu
void identificationCode() {
    int identificationCode;
    int dd,mm,yy;
    
    printf("\n--- Identification Code ---\n\n");
    printf("Enter the Identification Code: ");
    scanf("%d", &identificationCode);

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
    insert(identificationCode, dd, mm, yy);
    networkSimulation(2);
}

//Shows if you've been exposed with random code
void contagionAlarm() {
    printf("\n--- Contagion Alarm ---\n");

    srand(time(NULL));
    int randomCode;

    //Random identification code
    randomCode = rand() % 100 + 1;
    
    printf("\nYou may have been exposed!\n");
    printf("\nIdentification code: %d\n", randomCode);
    Sleep(2000);
    
}

int main() {
    int choice = 5;
    
    //Loops until the the exit option is picked
    while (1)
    {
        delete();
        printf("\n--- Welcome to Coronablinkern ---\n\n");
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
    return 0;
}