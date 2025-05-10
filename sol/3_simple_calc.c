#include <stdio.h>

int main() {
    char operator;
    double num1;
    double num2;
    double result;

    printf("Enter an operation ( +, -, :, /): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);
    
    switch (operator)
    {
    case '+':
        result = num1 + num2; 
        break;
    case '-':
        result = num1 - num2; 
        break;
    case '*':
        result = num1 * num2; 
        break;
    case '/':
        if(num2 == 0)
        {
            printf("Error! You can't divide by 0!");
            return 1;
        }
        result = num1 / (double) num2; 
        break;
    default:
        printf("\n%c is not valid", operator);
        return 1;
    }

    printf("The result is %.3lf", result);
    return 0;
}