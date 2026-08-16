#include <stdio.h>
#define MAX(a, b) \
    do { \
        int ev = 1; \
        while(ev <= 1) { \
            if(a > b) { \
                printf("%d is greater than %d\n", a, b); \
            } else if(a < b) { \
                printf("%d is less than %d\n", a, b); \
            } else { \
                printf("%d is equal to %d\n", a, b); \
            } \
            ev++;  \
        }  \
    } while(0)
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    MAX(num1, num2);
    return 0;
}