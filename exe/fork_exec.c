/*
Exercise Instructions:

1. Objective:
   Use `fork` and `exec` to create a child process that runs a command and redirects its output to a file.

3. Expected Results:
   - Output of the command is written to a file.
   - The parent process prints whether the operation succeeded or failed.
*/

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

  // - Create a child process using `fork`.
  // - In the child process:
  // - Open a file for writing.
  // - Redirect standard output to the file.
  // - Execute a command using `execlp`.
  // - In the parent process:
  // - Wait for the child process to finish.
  // - Print success or failure based on the child's exit status.

  return 0;
}