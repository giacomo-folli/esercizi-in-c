#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

#define ARR_SIZE 10

int main(int argc, char *argv[])
{
  // 2 Processes
  // Child generates random numbers and send them to the parent
  // Parent sum them all up and print the result

  int pipefd[2];
  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    return 1;
  }

  int id = fork();
  if (id == -1)
  {
    printf("Error in forkking the process");
    return 1;
  }

  if (id == 0)
  {
    // Child
    close(pipefd[0]);

    // generate random number
    int n, i;
    int nums[ARR_SIZE];
    srand(time(NULL));
    n = rand() % 10 + 1;

    for (i = 0; i < n; i++)
    {
      nums[i] = rand() % 11;
    }

    printf("Child: rand nums size is %d\n", n);

    // send data size
    if (write(pipefd[1], &n, sizeof(int)) < 0)
    {
      perror("child wrote data size");
      return 2;
    }

    // send data
    if (write(pipefd[1], &nums, sizeof(int) * ARR_SIZE) < 0)
    {
      perror("child wrote data");
      return 3;
    }

    close(pipefd[1]);
  }
  else
  {
    // Parent
    close(pipefd[1]);
    int read_nums[ARR_SIZE] = {};
    int n, i, sum;

    // receive data size
    if (read(pipefd[0], &n, sizeof(int)) < 0)
    {
      perror("parent read data size");
      return 4;
    }

    printf("Parent: rand nums size is %d\n", n);

    // receive data
    if (read(pipefd[0], &read_nums, sizeof(int) * n) < 0)
    {
      perror("parent read data");
      return 5;
    }

    close(pipefd[0]);

    // print number
    for (i = 0; i < n; i++)
    {
      printf("%d)  %d\n", i, read_nums[i]);
      sum += read_nums[i];
    }

    printf("\nFinal sum is %d\n", sum);
  }

  wait(NULL);

  return 0;
}