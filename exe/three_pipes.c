#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd[3][2];

    for (int i = 0; i < 3; i++) {
        if (pipe(fd[i]) < 0) {
            return 1;
        }
    }

    int pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
    }

    if (pid1 == 0) {
        // Child 1
        close(fd[0][1]);
        close(fd[1][0]);
        int read_num;

        if (read(fd[0][0], &read_num, sizeof(int)) < 0) {
            return 4;
        }
        close(fd[0][0]);

        read_num += 5;

        if (write(fd[1][1], &read_num, sizeof(int)) < 0) {
            return 4;
        }

        close(fd[1][1]);
        return 0;
    }

    int pid2 = fork();
    if (pid2 == 0) {
        // Child 2
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[2][0]);
        close(fd[1][1]);
        int read_second_num;

        if (read(fd[1][0], &read_second_num, sizeof(int)) < 0) {
            return 2;
        }

        close(fd[1][0]);

        read_second_num += 5;

        if (write(fd[2][1], &read_second_num, sizeof(int)) < 0) {
            return 2;
        }
        close(fd[2][1]);
        return 0;
    }

    // Parent
    close(fd[0][0]);
    close(fd[2][1]);

    srand(time(NULL));
    int rand_num = rand() % 10;
    int final_num;

    printf("initial number is %d\n", rand_num);

    if (write(fd[0][1], &rand_num, sizeof(int)) < 0) {
        return 1;
    }

    if (read(fd[2][0], &final_num, sizeof(int)) < 0) {
        return 3;
    }

    close(fd[0][1]);
    close(fd[2][0]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("final number is  %d\n", final_num);

    // wait(NULL);
    return 0;
}