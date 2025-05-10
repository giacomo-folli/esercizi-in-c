/*
Exercise Instructions:

1. Objective:
   Write a program to classify a person's age based on input.

2. Steps:
   - Prompt the user to enter their age.
   - Use conditional statements to handle different age ranges
   - Print appropriate messages for each case.

3. Expected Results:
   - Input: Age value.
   - Output: A message describing the age category.
*/

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