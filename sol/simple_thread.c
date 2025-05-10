#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* my_turn(void* arg);
void your_turn();

int main(int argv, char* argc[]) {
    pthread_t newthread;
    int* result;

    pthread_create(&newthread, NULL, my_turn, NULL);
    your_turn();

    pthread_join(newthread, (void*)&result);
    printf("got %d\n", *result);
    return 0;
}

void* my_turn(void* arg) {
    int* intptr = (int*)malloc(sizeof(int));

    printf("calculating...\n");

    for (int i = 0; i < 4; i++) {
        (*intptr)++;
        sleep(1);
    }
    printf("calculated %d\n", *intptr);

    return intptr;
}

void your_turn() {
    printf("some stuff...\n");
    sleep(1);
    printf("other stuff...\n");

    return;
}
