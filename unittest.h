#include <stdio.h>
#ifndef UNITTESTH
#define UNITTESTH
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define TEST_CASE(name) printf(ANSI_COLOR_BLUE"\nRUNNING CASE"ANSI_COLOR_RESET": %s\n", name);
#define VERIFY(cond, msg) if (cond) printf(ANSI_COLOR_GREEN"SUCCESS"ANSI_COLOR_RESET": %s\n", msg); else printf(ANSI_COLOR_RED"FAIL"ANSI_COLOR_RESET": %s\n", msg);

#endif