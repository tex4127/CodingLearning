#include <stdio.h>

int i;

void counterByValue(int);
void counterByRef(int*);

int main()
{
    i = 7;
    printf("Value Before counterByValue -> %d\n", i);
    counterByValue(i);
    printf("Value After counterByValue -> %d\n", i);

    printf("Value Before counterByRef -> %d\n", i);
    counterByRef(&i);
    printf("Value After counterByRef -> %d\n", i);

    return 0;
}

//This deomonstrates what happens when we pass by value 
void counterByValue(int c)
{
    c = c + 1;
    printf("Value Durring counterByValue -> %d\n", c);
}

void counterByRef(int* c)
{
    *c = *c + 1;
    printf("Value Durring counterByRef -> %d\n", *c);
}