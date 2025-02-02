#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int pipefd[2];
  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    return 1;
  }

  int cpid = fork();
  if (cpid == -1)
  {
    perror("fork");
    return 2;
  }

  if (cpid == 0)
  {
    // Child process
    int input;
    if (read(pipefd[0], &input, sizeof(int)) == -1)
    {
      printf("Child Error while reading\n");
      return 3;
    }
    printf("Child read %d\n", input);

    input *= 2;
    if (write(pipefd[1], &input, sizeof(int)) == -1)
    {
      printf("Child Error while writing\n");
      return 3;
    }
    printf("Child wrote %d * 2 = %d\n", input / 2, input);
  }
  else
  {
    // Parent
    srand(time(NULL));
    int random_num = rand() % 20;
    int final_num;

    printf("Initial num is %d\n", random_num);

    if (write(pipefd[1], &random_num, sizeof(int)) == -1)
    {
      printf("Parent error while writing\n");
      return 3;
    }
    printf("Parent wrote %d\n", random_num);

    // Could have also created 2 different pipes instead of wait()
    // 1 for communication Parent -> Childres
    // 1 for communication Childres -> Parent
    wait(NULL);

    if (read(pipefd[0], &final_num, sizeof(int)) == -1)
    {
      printf("Parent error while reading final\n");
      return 3;
    }
    printf("Parent read final %d\n", final_num);
  }

  close(pipefd);
}