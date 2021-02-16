#include <stdio.h>

struct A{
    char c[2];
    int i;
    double d;
}a;


int main(){
    FILE* f = fopen("test.txt","w");
    a.c[0] = 'a';
    a.c[1] = 'b';
    a.i = 1;
    a.d = 2.0;

    fprintf(f,"%c",a.c[0]);

}