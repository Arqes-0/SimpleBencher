#include <stdio.h>
#include <time.h>
#define encontrar 40000

double calculated(clock_t start, clock_t end);

int main() {
  printf("\nStarting benchmark, this might take a while...\n");
  clock_t inicio, final;
  inicio = clock();
  for (int primos = 0; primos < encontrar;) {
    static int numero = 3;
    int flag = 0;
    for (int i = 2; i < numero; i++) {
      if (numero % i == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      primos++;
    }
    numero++;
  }
  final = clock();
  double algo = calculated(inicio, final);
  double score = encontrar / algo;
  printf("Primes: %d\n", encontrar);
  printf("Score: %f\n", score * 20);
  printf("Time: %f Seconds\n", algo / 1000);
}

double calculated(clock_t start, clock_t end) {

  return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}
