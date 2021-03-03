#include "date.h"
#include "unittest.h"
#include <stdio.h>

int main() {

    CurrentDate d1;
    Date d2, d3, d4;

    TEST_CASE("Get current date");
    VERIFY(getCurrentDate(&d1), "Getting todays date: ");
    printf("%d/%d/%d\n", d1.day, d1.month, d1.year);

    TEST_CASE("Set date");
    VERIFY(setDate(&d2, 11, 02, 2021), "Setting 11/02/2021 as date");

    TEST_CASE("Set date");
    VERIFY(setDate(&d3, 55, 02, 2021), "Setting 55/02/2021 as date");

    TEST_CASE("Set date");
    VERIFY(setDate(&d4, 11, 55, 2021), "Setting 06/55/2021 as date");

    TEST_CASE("Check date");
    VERIFY(checkDate(d2), "Checking if 11/02/2021 is valid date");

    TEST_CASE("Check date");
    VERIFY(!checkDate(d3), "Checking if 55/02/2021 is invalid date");

    TEST_CASE("Check date");
    VERIFY(!checkDate(d4), "Checking if 11/55/2021 is invalid date\n");

    TEST_CASE("Check date");
    VERIFY(!checkDate(d4), "Checking if 11/55/2021 is invalid date\n");

    return 0;
}