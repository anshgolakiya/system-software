#include <stdio.h>
#define SWAP(a, b) \
    do { \
        int ev = 1; \
        while(ev <= 1) { \
            int temp = a; \
            a = b; \
            b = temp; \
            printf("After swapping: a = %d, b = %d\n", a, b); \
            ev++; \
        } \
    } while(0)
int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    SWAP(a, b);
    return 0;
}