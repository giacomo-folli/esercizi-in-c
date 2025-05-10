#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int x = 0;

void handle_sigusr1(int sig);

int main(int argv, char *arch[])
{
  int id = fork();
  if (id == -1)
  {
    printf("Error in forking this process\n");
    return 1;
  }

  if (id == 0)
  {
    // Child
    sleep(5);
    kill(getppid(), SIGUSR1);
  }
  else
  {
    // Parent
    struct sigaction act = {0};
    act.sa_flags = SA_RESTART;
    act.sa_handler = &handle_sigusr1;
    sigaction(SIGUSR1, &act, NULL);

    printf("What is 3 x 5? \n");
    scanf("%d", &x);

    if (x == 15)
    {
      printf("Success!\n");
    }
    else
    {
      printf("Failed!\n");
    }
  }

  wait(NULL);

  return 0;
}

void handle_sigusr1(int sig)
{
  if (x == 0)
  {
    printf("\nThe hint is already in you!\n");
  }
}
