#include <stdio.h>
#include "date.h"

//Checks if the date is correct
bool checkDate(int dd, int mm, int yy) {
    //Check year
        if (yy >= 1900 && yy <= 9999)
        {
            //Check month
            if (mm >= 1 && mm <= 12)
            {
                //Check days
                if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                    return true;
                else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                    return true;
                else if ((dd >= 1 && dd <= 28) && (mm == 2))
                    return true;
                else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                    return true;
                else
                    printf("\nDay is not valid.\n\n");
                    return false;
            }
            else
            {
                printf("\nMonth is not valid.\n\n");
                return false;
            }
        }
        else
        {
            printf("\nYear is not valid.\n\n");
            return false;
        }
}