#include <stdio.h>
#include <stdlib.h>

#include "hello.h"

int main(void)
{
    int a = 5;
    SayHello();
    for (int i = 0; i < 30000; i++)
    {
        int *p = malloc(3000);
        p++;
    }
    a++;
    return 0;
}

