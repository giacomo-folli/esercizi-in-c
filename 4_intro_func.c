#include <stdio.h>

void greet(char[], int);
int calculateAge(int);

int main()
{
    char name[] = "Bro";
    int age = 21;

    int newAge = calculateAge(age);
    greet(name, newAge);

    return 0;
}

void greet(char name[], int age)
{
    for (int i = 0; i < 5; i++)
    {
        printf("\nHappy birthday, %s!!", name);
    }
    printf("\nNow you are %d", age);
}

int calculateAge(int x)
{
    int newAge = x + 1;
    return newAge;
}