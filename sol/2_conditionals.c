#include <stdio.h>

int main()
{
    int age;

    printf("\nEnter your age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are 18 or older");
    }
    else if (age == 0)
    {
        printf("You are 0!!");
    }
    else if (age < 0)
    {
        printf("You aren't born yet");
    }
    else
    {
        printf("You are younger than 18");
    }

    return 0;
}