#include <stdio.h>

void swap_print(int, int);

void swap(int*, int*);

int main(void)
{
    int a = 10;
    int b = 15;
    printf("Starting Variables: a = %d | b = %d\n", a, b);
    swap(&a,&b);
    printf("After Swap: a = %d | b = %d\n", a, b);
    return 0;
}

void swap(int* ap, int* bp)
{
    int tp = *ap;
    *ap = *bp;
    *bp = tp;
    return;
}

void swap_print(int a, int b)
{
    printf("a = %d | b = %d\n", b, a);
    return;
}