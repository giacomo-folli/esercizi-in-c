#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARR_SIZE 10

void* add_first_half(void* arg);
void* add_second_half(void* arg);

int main(int argv, char* argc[]) {
    srand(getpid());

    pthread_t thread1;
    pthread_t thread2;
    int *res1, *res2, total;

    pthread_create(&thread1, NULL, &add_first_half, NULL);
    pthread_create(&thread2, NULL, &add_second_half, NULL);

    pthread_join(thread1, (void*)&res1);
    pthread_join(thread2, (void*)&res2);

    total = (*res1) + (*res2);

    printf("res1 %d\n", *res1);
    printf("res2 %d\n", *res2);
    printf("final %d\n", total);

    return 0;
}

void* add_first_half(void* arg) {
    int nums[ARR_SIZE] = {0};
    int* sum = (int*)malloc(sizeof(int));

    for (int i = 0; i < ARR_SIZE; i++) {
        nums[i] = rand() % 10;
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        (*sum) += nums[i];
    }

    printf("partial from 1 %d\n", *sum);

    return sum;
}
void* add_second_half(void* arg) {
    int nums[ARR_SIZE] = {0};
    int* sum = (int*)malloc(sizeof(int));

    for (int i = 0; i < ARR_SIZE; i++) {
        nums[i] = rand() % 10;
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        (*sum) += nums[i];
    }

    printf("partial from 2 %d\n", *sum);

    return sum;
}