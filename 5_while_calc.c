#include <stdio.h>

int main()
{
    char operator;
    char quit;
    double num1;
    double num2;
    double result;
    int active = 1;

    printf("Welcome to this simple calculator!");

    do
    {
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
                continue;
            }
            result = num1 / (double)num2;
            break;
        default:
            printf("%c is not valid", operator);
            continue;
        }

        scanf("%c");
        printf("The result is %.3lf", result);
        printf("\nDo you want to quit? y/n ");
        scanf("%c", &quit);

        if (quit == 'y')
        {
            return 0;
        }
    } while (active == 1);

    return 0;
}