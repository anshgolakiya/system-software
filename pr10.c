#include <stdio.h>
#define MAX(a, b) \
    (a > b ? a : b)

#define MAX3(a ,b , c) \
    do {  \
        int result = MAX(MAX(a, b), c); \
        printf("The maximum of %d, %d and %d is %d\n", a, b, c, result); \
    } while(0)
int main() {
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    MAX3(num1, num2, num3);
    return 0;
}