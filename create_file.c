#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 4098

void main()
{
  char data[DATA_SIZE];
  FILE *ptr = NULL;

  ptr = fopen("create_file.txt", "w");

  if (ptr == NULL)
  {
    perror("zio cane non funziono");
    return;
  }

  printf("Zio cane scrivi qualcosa:\n");
  fgets(data, DATA_SIZE, stdin);

  int success = fputs(data, ptr);

  if (success < 0)
  {
    printf("zio cane non ho scritto\n");
    return;
  }
  printf("File creato e salvato con successo zio can. :) \n");

  fclose(ptr);

  return;
}