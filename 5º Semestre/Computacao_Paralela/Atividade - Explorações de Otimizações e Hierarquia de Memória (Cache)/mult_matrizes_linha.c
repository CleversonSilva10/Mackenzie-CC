#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> 
#include <time.h>

void printMatriz(int **matriz, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      if (matriz[i][j] < 10) {
        printf("0%d | ", matriz[i][j]);
      } else {
        printf("%d | ", matriz[i][j]);
      }
    }
    printf("\n");
  }
}

int **calculateProductMatrix1(int **a, int **b, int tamanho) {

  int **result = calloc(tamanho, sizeof(int *));
  for (int i = 0; i < tamanho; i++)
    result[i] = calloc(tamanho, sizeof(int));

  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      for (int k = 0; k < tamanho; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return result;
}

int main(void) {

  setlocale(LC_ALL, "Portuguese");

  int tamanho;
  double tempo_gasto;
  time_t inicio, fim;

  printf("Digite a dimensão das duas matrizes quadradas: ");
  scanf("%d", &tamanho);

  int **a, **b, **result;

  a = calloc(tamanho, sizeof(int *));
  b = calloc(tamanho, sizeof(int *));

  for (int i = 0; i < tamanho; i++) {
    a[i] = calloc(tamanho, sizeof(int *));
    b[i] = calloc(tamanho, sizeof(int *));
  }

  srand(time(NULL));
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      a[i][j] = rand() % 40;
      b[i][j] = rand() % 40;
    }
  }

  // EXIBINDO MATRIZES

  printMatriz(a, tamanho);
  printf("\n\n");
  printMatriz(b, tamanho);

  // EXIBINDO PARES NA MATRIZ A

  printf("\n\nValores na matriz A que são pares: \n");
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      if (a[i][j] % 2 == 0) {
        printf("%d\n", a[i][j]);
      }
    }
  }

  // MULTIPLICAÇÃO DE MATRIZES EM "FORMA DE LINHA"
  printf("\nUsando multiplicação 'em linha': \n");
  time(&inicio);
  result = calculateProductMatrix1(a, b, tamanho);
  time(&fim);
  tempo_gasto = (double) (fim-inicio);
  printf("Tempo: %f", tempo_gasto);
  return 0;
}