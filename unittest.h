#include <stdio.h>
#ifndef UNITTESTH
#define UNITTESTH

#define TEST_CASE(name) printf("\nRUNNING CASE: %s\n", name);
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

#endif