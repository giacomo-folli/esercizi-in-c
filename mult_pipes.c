#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define PROC_NUM 10

int main() {
    int pids[PROC_NUM];
    int pipefd[PROC_NUM + 1][2];

    for (int i = 0; i < PROC_NUM + 1; i++) {
        if (pipe(pipefd[i]) < 0) {
            perror("pipe");
            return 1;
        }
    }

    for (int i = 0; i < PROC_NUM; i++) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("fork");
            return 2;
        }

        if (pids[i] == 0) {
            for (int j = 0; j < PROC_NUM; j++) {
                if (i != j) {
                    close(pipefd[j][0]);
                }

                if (i + 1 != j) {
                    close(pipefd[j][1]);
                }
            }

            int x;
            if (read(pipefd[i][0], &x, sizeof(int)) < 0) {
                perror("child read");
                return i;
            }

            x += 1;

            if (write(pipefd[i + 1][1], &x, sizeof(int)) < 0) {
                perror("child write");
                return i;
            }

            close(pipefd[i][0]);
            close(pipefd[i + 1][1]);

            return 0;
        }
    }

    srand(getpid());
    int y = rand() % 11;
    if (write(pipefd[0][1], &y, sizeof(int)) < 0) {
        perror("write");
        return 5;
    }

    int total;
    if (read(pipefd[PROC_NUM][0], &total, sizeof(int)) < 0) {
        perror("read");
        return 5;
    }

    close(pipefd[0][1]);
    close(pipefd[PROC_NUM][0]);

    for (int i = 0; i < PROC_NUM; i++) {
        wait(NULL);
    }

    printf("Initial number: %d\n", y);
    printf("Number of cycles: %d\n", PROC_NUM);
    printf("Final resul: %d\n", total);

    return 0;
}