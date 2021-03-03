#include "list.h"
#include "unittest.h"
#include <stdio.h>

int main() {

    TEST_CASE("Insert ID and date in list");
    VERIFY(insert(35, 05, 03, 2021), "Inserting ID: 35 and date: 11/02/2021");

    TEST_CASE("Insert ID and date in list");
    VERIFY(insert(67, 07, 03, 2021), "Inserting ID: 67 and date: 15/02/2021");

    TEST_CASE("Insert ID and date in list");
    VERIFY(insert(26, 10, 03, 2021), "Inserting ID: 26 and date: 21/02/2021");

    TEST_CASE("Insert ID and date in list");
    VERIFY(insert(84, 15, 03, 2021), "Inserting ID: 84 and date: 25/03/2021");

    TEST_CASE("Insert ID and date in list");
    VERIFY(insert(12, 25, 03, 2021), "Inserting ID: 15 and date: 12/03/2020");

    TEST_CASE("Delete dates 21 days older than current date");
    VERIFY(delete(), "Deleting date(s)");

    TEST_CASE("Print list");
    VERIFY(printList(), "Printing the whole list\n")

    return 0;
}