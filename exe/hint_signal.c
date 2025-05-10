/*
Exercise Instructions:

1. Objective:
   Use signals to communicate between a parent and child process.

3. Expected Results:
   - Input: User's answer to a question.
   - Output: A success or failure message, and a hint if the signal is received.
*/

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
   // - Create a child process using `fork`.

   // - In the child process, send a signal to the parent after a delay.
   // - In the parent process:
   // - - Set up a signal handler to respond to the signal.
   // - - Prompt the user for input and check their response.
   // - - Print appropriate messages based on the input and signal.

   return 0;
}
