#include <stdio.h>
#define PI 3.14

int main() {
    int radius;
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);
    float area = PI * radius * radius ;
    printf("The area of the circle with radius %d is %.2f\n", radius,area);
    return 0;
}
