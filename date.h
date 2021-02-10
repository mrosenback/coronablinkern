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