#include "date.h"
#include <stdio.h>

bool setDate(Date* date, int dd, int mm, int yy) {
    date->day = dd;
    date->month = mm;
    date->year = yy;

    return true;
}

bool checkDate(Date date) {
    //Check year
        if (date.year >= 1900 && date.year <= 9999)
        {
            //Check month
            if (date.month >= 1 && date.month <= 12)
            {
                //Check days
                if ((date.day >= 1 && date.day <= 31) && (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12))
                    return true;
                else if ((date.day >= 1 && date.day <= 30) && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11))
                    return true;
                else if ((date.day >= 1 && date.day <= 28) && (date.month == 2))
                    return true;
                else if (date.day == 29 && date.month == 2 && (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0)))
                    return true;
                else
                    printf("Day is not valid.\n");
                    return false;
            }
            else
            {
                printf("Month is not valid.\n");
                return false;
            }
        }
        else
        {
            printf("Year is not valid.\n");
            return false;
        }
}