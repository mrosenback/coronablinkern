#include <stdbool.h>

typedef struct _Date {
    int day;
    int month;
    int year;
} Date;

bool checkDate(int dd, int mm, int yy);