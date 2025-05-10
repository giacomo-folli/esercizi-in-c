#include <stdio.h>
#include <stdlib.h>

void writeStudentData(FILE *, int);

int main()
{
    int num;

    printf("Enter number of students: ");
    scanf("%d", &num);

    FILE *fptr = NULL;
    fptr = (fopen("C:\\Users\\giaco\\Desktop\\test.txt", "w"));

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    writeStudentData(fptr, num);

    fclose(fptr);
    return 0;
}

void writeStudentData(FILE *file, int num)
{
    char name[50];
    int marks, i;

    for (int i = 0; i < num; i++)
    {
        printf("Student %d\nEnter name: ", i + 1);
        scanf("%s", name);

        printf("Enter mark: ");
        scanf("%d", &marks);

        fprintf(file, "\nName: %s \nMarks=%d \n+++++++++++++++\n", name, marks);
    }
}
