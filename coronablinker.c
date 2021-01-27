#include <stdio.h>
#include <Windows.h>

void networkSimulation() {
    printf("\nOpening code received. Sending information to the server.\n");
    
    for(int i=0;i<3;i++) {
        Sleep(1000);
        printf(".");
    }
    Sleep(1000);
    
    printf("\nInformation has succesfully been sent!\n");

    Sleep(1000);
}

void openingCode() {
    int openingCode;

    printf("\n--- Opening Code ---\n\n");
    printf("Enter your Opening Code: ");
    scanf("%d", &openingCode);
    networkSimulation();
}

void identificationCode() {
    int identificationCode;
    int dd,mm,yy;
    
    printf("\n--- Identification Code ---\n\n");
    printf("Enter the Identification Code: ");
    scanf("%d", &identificationCode);

    while(1) {
        printf("Enter the date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &dd, &mm, &yy);
        //Check year
        if (yy >= 1900 && yy <= 9999)
        {
            //Check month
            if (mm >= 1 && mm <= 12)
            {
                //Check days
                if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                    break;
                else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                    break;
                else if ((dd >= 1 && dd <= 28) && (mm == 2))
                    break;
                else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                    break;
                else
                    printf("\nDay is not valid.\n\n");
            }
            else
            {
                printf("\nMonth is not valid.\n\n");
            }
        }
        else
        {
            printf("\nYear is not valid.\n\n");
        }
    }
    
    networkSimulation();
}

void contagionAlarm() {
    printf("\n--- Contagion Alarm ---\n\n");
}

int main() {
    int choice = 5;
    
    while (1)
    {
        printf("\n--- Welcome to Coronablinkern ---\n\n");
        printf("1< Enter an Opening Code if you have been infected.\n2< Enter Identification Code.\n3< Receive an Infection Alarm.\n4< Exit.\n\n");
        printf("Choose category (1, 2 or 3): ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            openingCode();
        } else if(choice == 2) {
            identificationCode();
        } else if(choice == 3) {
            contagionAlarm();
        } else if(choice == 4) {
            printf("\nExisting program. Goodbye!\n\n");
            break;
        } else {
            printf("\nError: Choose a valid category.\n");
            Sleep(2000);
        }
    }
    
    return 0;
}