#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fd = NULL;
  char data_char;

  fd = fopen("read_from_file", "r");
  if (fd == NULL)
  {
    perror("zio can aperto un casz");
    return 1;
  }

  do
  {
    data_char = fgetc(fd);
    putc(data_char, stdout);
  } while (data_char != EOF);

  return 0;
}