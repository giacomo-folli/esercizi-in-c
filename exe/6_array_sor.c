#include <stdio.h>

void sort(int[], int);
void printArray(int[], int);

int main()
{

    int array[] = {9, 1, 4, 8, 7, 6, 3, 5, 4, 2, 1, 9, 3, 5};
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);
    printArray(array, size);

    return 0;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
}

void sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}