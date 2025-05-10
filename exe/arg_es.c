#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("arguments number %d\n", argc);

    for (int i = 1; i < argc; i++)
    {
        printf("%d' argument is %s\n", i, argv[i]);
    }

    return 0;
}