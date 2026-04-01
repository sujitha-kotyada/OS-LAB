#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
pthread_t phil[N];
pthread_mutex_t mutex;
pthread_cond_t self[N];

void test(int i) {
    if (state[(i+4)%N] != EATING && state[i]==HUNGRY && (state[(i+1)%N] != EATING)) {
        state[i] = EATING;
        pthread_cond_signal(&self[i]);
    }
}

void pickup(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", i);
    test(i);
    while (state[i] != EATING) {
        pthread_cond_wait(&self[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void putdown(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d is THINKING\n", i);
    test((i+4)%N);
    test((i+1)%N);
    pthread_mutex_unlock(&mutex);
}

void *philosopher(void *num) {
    int i = *(int *)num;
    do {
        printf("Philosopher %d is THINKING\n", i);
        sleep(1);
        pickup(i);
        printf("Philosopher %d is EATING\n", i);
        sleep(2);
        putdown(i);
    } while(1);
    return NULL;
}

int main() {
    int i, id[N];
    pthread_mutex_init(&mutex, NULL);
    for(i=0; i<N; i++) {
        pthread_cond_init(&self[i], NULL);
        state[i] = THINKING;
    }
    for(i=0; i<N; i++) {
        id[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &id[i]);
    }
    for(i=0; i<N; i++) {
        pthread_join(phil[i], NULL);
    }
    return 0;
}