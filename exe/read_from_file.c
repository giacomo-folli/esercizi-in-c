#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Declare a file pointer and a variable to store characters.
  FILE *fd = NULL;
  char data_char;

  // Open a file in read mode and check for errors.
  fd = fopen("read_from_file", "r");
  if (fd == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  // Read characters from the file in a loop and print them.
  do
  {
    data_char = fgetc(fd);
    putc(data_char, stdout);
  } while (data_char != EOF);

  // Return success.
  return 0;
}