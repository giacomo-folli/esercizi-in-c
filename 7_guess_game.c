#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MIN = 1;
    const int MAX = 100;
    int guess = 0;
    int guesses = 0;
    int answer = 0;

    // use current time as seed
    srand(time(0));

    // generate random number between MIN and MAX
    answer = (rand() % MAX) + MIN;

    do
    {
        printf("Enter a guass: ");
        scanf("%d", &guess);
        if (guess == answer)
        {
            printf("CORRECT!!\n");
        }
        else if (guess > answer)
        {
            printf("Too high!\n");
        }
        else
        {
            printf("Too low!\n");
        }
        guesses++;
    } while (guess != answer);

    printf("++++++++++++++++++++++++\n");
    printf("answer: %d\n", answer);
    printf("guesses: %d\n", guesses);
    printf("++++++++++++++++++++++++");

    return 0;
}