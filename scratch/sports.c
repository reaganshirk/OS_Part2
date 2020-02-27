#include <stdio.h>
#include "string.h"

#define PI 3.14159265358979
#define TRUE 1
#define FALSE 0
#define myname "Reagan Shirk"
#define HALFOF(x) x/2
#define TRACE { printf("Executing %s line %d\n", __FILE__, __LINE__);  }

// void main() is still allowed but unconventional
int main(int argc, char** argv)
{
    // char
    // short
    // long

    long int val = 65530000000000;
    unsigned val2 = -65530;

    printf("My val: %ld\n", val);
    printf("My val: %d\n", val2);

    //sizeof(whatever is in here);
    printf("The size of 'char' is: %ld\n", sizeof(char));
    printf("The size of 'int' is: %ld\n", sizeof(int));
    printf("The size of 'long' is: %ld\n", sizeof(long));
    printf("The size of 'short' is: %ld\n", sizeof(short));

    printf("We have %d command line arguments\n", argc);

    if (argc > 1)
    {
        // we have extra command line arguments
        short i = 1;
        for (i; i < argc; ++i)
        {
            printf("%d: %s\n", i, argv[i]);
        }
    }

    // Pointers
    int box; // Make space to hold 4 bytes [ ]
    box = 7;
    int* boxpointer = &box; // returns boxes location in memory

    printf("box value = %d\n", box); // should print out the value
    printf("box address = %p\n", &box); // location in memory
    printf("box pointer = %p\n", boxpointer); // location in memory
    printf("box pointer value = %d\n", *boxpointer); // should print the value
    printf("\n");

    // Describing (deciphering) variables/expressions
    // * = 'pointer to'
    // [] = 'array of'
    // () = 'function returning'

    // Step 1: Find intendifier
    // Step 2: Look for symbols on the right until you hit the end
    // Step 3: Look to the left

    // int *p[];
    // - p
    // - is an array of
    // - a pointer to
    // - integer
    // So we say: "p is an array of a pointer to an integer"

    return 0;
}
