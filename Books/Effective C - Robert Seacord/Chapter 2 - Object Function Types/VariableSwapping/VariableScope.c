#include <stdio.h>

//Global variable, scope is to the file
int j; 

void foo(int);

int main(void)
{
    j = 1;
    printf("j to start main function -> %d\n", j);
    foo(4);
    printf("j after foo function -> %d\n", j);
    return 0;
}


void foo(int i)
{
    int j = i;
    i++;
    for (i = 0; i < 2; i++)
    {
        int j = 2;
        printf("j inside for loop -> %d\n", j);
    }
    printf("j out of for loop -> %d\n", j);
}