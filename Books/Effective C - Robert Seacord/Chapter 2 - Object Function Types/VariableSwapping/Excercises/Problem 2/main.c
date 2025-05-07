/////////////////////////////////////////////////
///
//  Declare an array of three pointers to functions and invoke
//  the proper function based on an idex value passed in as an
//  argument.
//
///
/////////////////////////////////////////////////


#include <stdio.h>

void foo1(void)
{
    printf("Foo1 Called!\n");
}

void foo2(int a)
{
    printf("Foo2 Called! Arg -> %d\n", a);
}

void foo3(int a, int b)
{
    int max = a > b ? a : b;
    printf("Foo3 Called! %d is the larger value of %d and %d\n", max, a, b);
}



void (*fip[])() = {foo1, foo2, foo3};

int main()
{
    printf("Calling Index 1\n");
    fip[0]();
    printf("Calling Index 2\n");
    fip[1](10);
    printf("Calling Index 3\n");
    fip[2](25, 15);
    return 0;
}