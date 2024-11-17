#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tests
{
    int a;
} *Tests;

typedef struct Tests2
{
    int b;
    Tests c[10];
} Tests2;



int main()
{
    Tests t = (Tests)malloc(sizeof(Tests));
    Tests t2 = t;
    printf("%d\n", t);
    printf("%d\n", t2);

    t = (Tests)malloc(sizeof(Tests));
    printf("%d\n", t);
    printf("%d\n", t2);
    // printf("%d\n", t2->c[0]->a);
}