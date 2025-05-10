/*
Exercise Instructions:

1. Objective:
   Create a calculator that repeatedly performs operations until the user decides to quit.

2. Steps:
   - Prompt the user to input an operator and two numbers.
   - Use a loop to allow multiple calculations.
   - Perform the operation based on the operator and handle invalid inputs.
   - Handle division by zero as an error case.
   - Ask the user if they want to quit after each calculation.

3. Expected Results:
   - Input: Operator, two numbers, and quit confirmation.
   - Output: The result of the operation or an error message.
*/

#include <stdio.h>

int calc()
{
    char operator;
    double num1;
    double num2;
    double result;

    printf("\nEnter an operation ( +, -, :, /): ");
    scanf("%c", &operator);

    scanf("%c");

    printf("\nEnter the first number: ");
    scanf("%lf", &num1);

    printf("\nEnter the second number: ");
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
        if (num2 == 0)
        {
            printf("Error! You can't divide by 0!");
            return 2;
        }
        result = num1 / (double)num2;
        break;
    default:
        printf("%c is not valid", operator);
        return 2;
    }

    scanf("%c");
    printf("The result is %.3lf", result);
}

int main()
{
    char quit;
    int active = 1;

    printf("Welcome to this simple calculator!");

    do
    {

        printf("\nDo you want to quit? y/n ");
        scanf("%c", &quit);

        active = calc();
    } while (active == 1);

    return 0;
}