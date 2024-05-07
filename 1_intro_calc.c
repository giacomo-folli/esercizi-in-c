#include <stdio.h>
#include <math.h>

typedef struct {
    double circumference;
    double area;
} Results;

int main() {
    const double PI = 3.14159;
    double radius;
    Results results;

    printf("\nEnter the radius: ");
    scanf("%lf", &radius);

    results.circumference = 2 * radius * PI;
    results.area = pow(radius, 2);

    printf("\nResults:\n");
    printf("Circumference: %.3lf\n", results.circumference);
    printf("Area:          %.3lf\n", results.area);

    return 0;
}