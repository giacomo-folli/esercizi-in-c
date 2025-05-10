/*
Exercise Instructions:

1. Objective:
   Use functions to calculate a new age and display a birthday message.

2. Steps:
   - Create a function to calculate the new age by incrementing the current age.
   - Create another function to print a birthday message multiple times and display the new age.
   - Call these functions from the `main` function with appropriate arguments.

3. Expected Results:
   - Output: A birthday message repeated multiple times and the updated age.
*/

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