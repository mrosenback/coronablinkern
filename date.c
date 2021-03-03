#include "date.h"
#include <stdio.h>
#include <time.h>

int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
                else {
                    printf("Day is not valid.\n");
                    return false;
                }      
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

bool getCurrentDate(CurrentDate* currentDate) {

    time_t now;
    time(&now);

    struct tm *local = localtime(&now);

    currentDate->day = local->tm_mday;
    currentDate->month = local->tm_mon + 1;
    currentDate->year = local->tm_year + 1900;

    return true;
}

int getDifference(CurrentDate dt1, Date dt2) {
    int n1 = dt1.year * 365 + dt1.day;
 
    for (int i = 0; i < dt1.month - 1; i++)
        n1 += monthDays[i];
 
    int n2 = dt2.year * 365 + dt2.day;
    for (int i = 0; i < dt2.month - 1; i++)
        n2 += monthDays[i];

    return (n2 - n1);
}