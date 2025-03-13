#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void id_alunos() {
  printf("\n--------------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("--------------------------------------------------\n");
}

void preencher_zero(int **matriz, int n, int n_colunas) {
  int i = 0, j = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n_colunas; j++) {
      matriz[i][j] = 0;
    }
  }
}

void imprimirMatriz(int **matriz, int n_linhas, int n_conlunas, char String1[20]) {
  printf("\n");
  printf("\tA\tG\tT\tA\tA\tC\tG\tC\tT\tA\n");
  for (int i = 0; i < n_linhas; i++) {
    if (i == 0) {
      printf("\t");
    }else{
      printf("%c\t", String1[i-1]);
    }
    for (int j = 0; j < n_conlunas; j++) {
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }
}

int maior(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int diferentes(int a, int b) {
  if (a != b) {
    return a;
  } else {
    return b;
  }
}

void Matriz_LCS(int **matriz, int n_linhas, int n_colunas,char letras1[20], char letras2[20]) {
  int i = 0, j = 0;
  for (i = 1; i < n_linhas; i++) {
    for (j = 1; j < n_colunas; j++) {
      if (letras1[i - 1] == letras2[j - 1]) {
        matriz[i][j] = matriz[i - 1][j - 1] + 1;
      } else {
        int valor = maior(matriz[i - 1][j], matriz[i][j - 1]);
        matriz[i][j] = valor;
      }
    }
  }
}

int main() {
  id_alunos();
  char String1[20];
  char String2[20];
  int **matriz, tamanho_string1, tamanho_string2, i;
  
  printf("Informe a String1: ");
  scanf("%s", String1);
  tamanho_string1 = strlen(String1);
  printf("Informe a String2: ");
  scanf("%s", String2);
  tamanho_string2 = strlen(String2);
  matriz = malloc(tamanho_string1 * sizeof(int *));
  for (i = 0; i < tamanho_string1; i++) {
    matriz[i] = malloc(tamanho_string2 * sizeof(int));
  }
  preencher_zero(matriz, tamanho_string1, tamanho_string2);
  //imprimirMatriz(matriz, tamanho_string1, tamanho_string2, String1);
  Matriz_LCS(matriz, tamanho_string1, tamanho_string2, String1, String2);
  imprimirMatriz(matriz, tamanho_string1, tamanho_string2, String1);

  i = tamanho_string1-1;
  int j = tamanho_string2-1;
  int posicao = tamanho_string1-1;
  printf("\n");

  while (posicao >= 0) {
    if (matriz[i][j] != matriz[i][j - 1]) {
      printf("%c", String1[posicao]);
      printf(" - [%d][%d]\n", i, j);
      posicao = posicao - 1;
      j = j - 1;
      i = i - 1;
    } else {
      posicao = posicao - 1;
      j = j - 1;
    }
  }

  printf("\n");
  return 0;
}