#include <stdio.h>
#define SQUARE(x)  \
    do { \
        int ev = 1; \
        while(ev <= 1) { \
            printf("Square of %d is %d\n", x, x * x); \
            ev++; \
        } \
    } while(0) 
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    SQUARE(num);
    return 0;
}