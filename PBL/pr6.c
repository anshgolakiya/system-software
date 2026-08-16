#include <stdio.h>
#define MACRO(r) \
    do { \
        int ev = 1; \
        while(ev <= 1) { \
            printf("area of circle is %f\n", 3.14 * r * r); \
            ev++; \
        } \
    } while(0)

int main() {
    int radius;
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);
    MACRO(radius);
    return 0;
}