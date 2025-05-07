///////////////////////////////////////////
///
//  This is the standard Hello World program
//  but written in C.
//
//  The main reasons for inclusion are for 
//  completeness and to get used to c IO.
//
///
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
    puts("Hello World"); //it should be noted that this can return an error that we can check for and return a failure value from the program
    //Alternatively, we could use printf("Hello World\n"); Or if we are feeling fancy printf("%s\n", "Hello World");
    return EXIT_SUCCESS; // pulled from stdlib. My hope is to not rely on stdlib ala Carmack in the Doom3/ID Tech 4 engine
}