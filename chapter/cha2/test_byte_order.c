#include <stdio.h>

int main(){
    int a = 0x12345678;
    int* add_a = &a;
    char* p = (char*)add_a;
    if(*p == 0x12)
        printf("it's big endian\n");
    else if(*p == 0x78)
        printf("it's little endian\n");
    else
        printf("something went wrong\n");
}