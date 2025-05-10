#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Shared variable to indicate thread completion
volatile int thread_done = 0;

void handler(int sig);
void *send_signals(void *arg);

int main(int argc, char *argv[]) {
    int main_pid = getpid();
    printf("main pid %d\n", main_pid);

    struct sigaction act = {0};
    act.sa_handler = &handler;
    if (sigaction(SIGTSTP, &act, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    pthread_t tthread;
    pthread_create(&tthread, NULL, &send_signals, &main_pid);

    int x = 1;              // Use a regular variable
    while (!thread_done) {  // Loop until thread_done is set to 1
        printf("x is %d\n", x);
        sleep(1);
    }

    // Retrieve the return value from the thread
    int *thread_return_value;
    pthread_join(tthread, (void **)&thread_return_value);

    // Print and free the return value
    printf("Thread returned: %d\n", *thread_return_value);
    free(thread_return_value);

    return 0;
}

void *send_signals(void *arg) {
    int *receiver = malloc(sizeof(int));
    int *return_value = malloc(sizeof(int));
    *return_value = 0;

    printf("thread received %d\n", *(int *)arg);
    *receiver = *(int *)arg;

    printf("thread targets %d\n", *receiver);

    for (int i = 0; i < 5; i++) {
        kill(*receiver, SIGTSTP);
        sleep(1);
    }

    *return_value += 2;  // Update the return value
    free(receiver);      // Free receiver memory

    thread_done = 1;      // Indicate thread completion
    return return_value;  // Return the pointer to return_value
}

void handler(int sig) {
    printf("received signal\n");
}
