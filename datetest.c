#include "date.h"
#include "unittest.h"
#include <stdio.h>

int main() {

    Date d1, d2, d3;

    TEST_CASE("Set date");
    VERIFY(setDate(&d1, 11, 02, 2021), "Setting 11/02/2021 as date");

    TEST_CASE("Set date");
    VERIFY(setDate(&d2, 55, 02, 2021), "Setting 55/02/2021 as date");

    TEST_CASE("Set date");
    VERIFY(setDate(&d3, 11, 55, 2021), "Setting 06/55/2021 as date");

    TEST_CASE("Check date");
    VERIFY(checkDate(d1), "Checking if 11/02/2021 is valid date");

    TEST_CASE("Check date");
    VERIFY(checkDate(d2), "Checking if 55/02/2021 is valid date");

    TEST_CASE("Check date");
    VERIFY(checkDate(d2), "Checking if 11/55/2021 is valid date\n");

    return 0;
}