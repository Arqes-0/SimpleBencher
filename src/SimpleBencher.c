#include <bits/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define primesToFind 150000
#define primesToFindSingle 40000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int numbers = 2;
int found = 0;

void *CalculatePrimes() {
  int foundCopy = 0;
  int numbersCopy = 0;
  while (foundCopy < primesToFind) {
    pthread_mutex_lock(&mutex);
    numbers++;
    numbersCopy = numbers;
    foundCopy = found;
    pthread_mutex_unlock(&mutex);
    int flagFound = 0;
    for (int i = 2; i < numbersCopy; i++) {
      if (numbersCopy % i == 0) {
        flagFound = 1;
        break;
      }
    }

    if (flagFound == 0) {
      pthread_mutex_lock(&mutex);
      found++;

      pthread_mutex_unlock(&mutex);
    }
  }
  return NULL;
}

void MultiCore() {
  sleep(2);
  printf("\nStarting benchmark, this might take a while...\n");
  long nCores = sysconf(_SC_NPROCESSORS_ONLN);
  pthread_t thread[nCores];
  struct timespec tStart, tEnd;

  clock_gettime(CLOCK_MONOTONIC, &tStart);

  for (int i = 0; i < nCores; i++) {
    pthread_create(&thread[i], NULL, CalculatePrimes, NULL);
  }
  for (int i = 0; i < nCores; i++) {
    pthread_join(thread[i], NULL);
  }

  clock_gettime(CLOCK_MONOTONIC, &tEnd);
  double scoreTime =
      (tEnd.tv_sec - tStart.tv_sec) + (tEnd.tv_nsec - tStart.tv_nsec) / 1e9;
  double score = primesToFind / scoreTime;
  printf("Primes: %d\n", primesToFind);
  printf("Score: %f\n", score);
  printf("Time: %f Seconds\n", scoreTime);
}
void SingleCore() {
  printf("\nStarting benchmark, this might take a while...\n");
  long nCores = sysconf(_SC_NPROCESSORS_ONLN);
  pthread_t thread[nCores];
  struct timespec tStart, tEnd;

  clock_gettime(CLOCK_MONOTONIC, &tStart);
  numbers = 3;
  for (int primes = 0; primes < primesToFindSingle;) { // increment
    int flagFound = 0; // to tell if a prime is found
    for (int i = 2; i < numbers; i++) {
      if (numbers % i == 0) {
        flagFound = 1;
        break;
      }
    }
    if (flagFound == 0) {
      primes++;
    }
    numbers++;
  }

  clock_gettime(CLOCK_MONOTONIC, &tEnd);
  double scoreTime =
      (tEnd.tv_sec - tStart.tv_sec) + (tEnd.tv_nsec - tStart.tv_nsec) / 1e9;
  double score = primesToFindSingle / scoreTime;
  printf("Primes: %d\n", primesToFindSingle);
  printf("Score: %f\n", score);
  printf("Time: %f Seconds\n", scoreTime);
}
int main() {
  system("clear");
again:;
  int UserChoice = 0;
  printf("\n What test do you want to run?\n"
         "	(1) SingleCore\n"
         "	(2) Multicore\n"
         "	(0) Exit\n\n\n"
         "Your Choice: ");
  scanf("%d", &UserChoice);
  switch (UserChoice) {
  case 1:
    SingleCore();
    break;
  case 2:
    MultiCore();
    break;
  case 0:
    return 0;
  default:
    goto again;
    break;
  }
  return 0;
}
