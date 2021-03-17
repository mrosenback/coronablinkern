#include <stdio.h>
#include <stdbool.h>

/**
 * Insert new identification code and date to list
 */
bool insert();

/**
 * Delete node that is older than 21 days
 */
bool delete();

/**
 * Read info from text file
 */
void readFromFile(FILE * fileptr);

/**
 * Write info to text file
 */
bool writeToFile(FILE * fileptr);

/**
 * Check if you've met someone who's sick
 */
bool checkContagion(int code);

/**
 * Print the list
 */
bool printList();