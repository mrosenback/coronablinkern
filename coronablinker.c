#include <stdio.h>
#include <Windows.h>

void networkSimulation() {
    printf("\nOpening code received. Sending information to the server.\n");
    
    for(int i=0;i<3;i++) {
        Sleep(1000);
        printf(".");
    }
    Sleep(1000);
    
    printf("\nInformation has succesfully been sent!");
}

void openingCode() {
    int openingCode;

    printf("\n--- Opening Code ---\n\n");
    printf("Enter your Opening Code: ");
    scanf("%d", &openingCode);
    networkSimulation();
}

void identificationCode() {
    printf("\n--- Identification Code ---\n\n");
}

void contagionAlarm() {
    printf("\n--- Contagion Alarm ---\n\n");
}

int main() {
    int choice = 5;

    printf("\n--- Welcome to Corornablinkern ---\n\n");
    printf("1< Enter an Opening Code if you have been infected.\n2< Enter Identification Code.\n3< Receive an Infection Alarm.\n4< Exit.\n\n");
    
    while (choice > 4)
    {
        printf("Choose category (1, 2 or 3): ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            openingCode();
        } else if(choice == 2) {
            identificationCode();
        } else if(choice == 3) {
            contagionAlarm();
        } else if(choice == 4) {
            break;
        } else {
            printf("Error: Choose a valid category.\n\n");
        }
    }
    
    return 0;
}