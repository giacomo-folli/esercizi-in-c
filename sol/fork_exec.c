#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int id = fork();

  if (id == 0)
  {
    // Child
    int fd = open("fork_exec.txt", O_WRONLY | O_CREAT, 0777);
    if (fd == -1)
    {
      printf("Error in ping from child proc\n");
      return 2;
    }

    dup2(fd, STDOUT_FILENO);
    close(fd);

    int err = execlp("ping", "ping", "-c", "3", "google.con", NULL);
    if (err == -1)
    {
      printf("Error in ping from child proc\n");
      return 2;
    }
  }
  else
  {
    // Parent
    int errno;
    wait(&errno);

    if (errno != 0)
    {
      printf("Failed\n");
    }
    else
    {
      printf("Success\n");
    }
  }

  return 0;
}