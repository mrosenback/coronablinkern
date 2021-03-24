#include <stdbool.h>

/**
 * ADT for representing a date.
 */
typedef struct _Date {
    int day;
    int month;
    int year;
} Date;

/**
 * ADT for representing current date.
 */
typedef struct _CurrentDate {
    int day;
    int month;
    int year;
} CurrentDate;

/**
 * Sets the date
 * @param date pointer to the date
 * @param dd the day
 * @param mm the month
 * @param yy the year
 */
bool setDate(Date* date, int dd, int mm, int yy);

/**
 * Checks if the date is correct
 * @param date the date to check
 */ 
bool checkDate(Date date);

bool getCurrentDate(CurrentDate* currentDate);

int getDifference(CurrentDate dt1, Date dt2);

bool isBefore(Date dt1, Date dt2);