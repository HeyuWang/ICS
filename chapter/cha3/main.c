#include <stdio.h>

void mulstore(long, long, long* );

int main()
{
    long d;
    mulstore(2,3,&d);
    printf("2 * 3 == %ld\n",d);
}

long mult2(long a, long b)
{
    long s = a*b;
    return s;
}