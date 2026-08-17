#include <stdio.h>
#define Max(a, b) ( (a) > (b) ? (a) : (b))
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("The maximum number is : %d \n",Max(num1,num2));
    return 0;
}
