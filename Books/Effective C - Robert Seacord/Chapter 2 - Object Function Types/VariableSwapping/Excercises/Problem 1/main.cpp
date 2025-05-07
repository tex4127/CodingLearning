/////////////////////////////////////////////////
///
//  Add a retrieve function to the ocunting example
//  from Listing 2-6 to get the current value of counter.
//
///
/////////////////////////////////////////////////


#include <stdio.h>

static unsigned long counter;

void increment(void)
{
    counter++;
}

unsigned int getCounter(void)
{
    return counter;
}

int main()
{
    counter = 0;
    for (int i = 0; i < 5; i++)
    {
        increment();
        printf("%lu\n", counter);
    }
    printf("Using getCounter -> %lu\n", getCounter());
    return 0;
}