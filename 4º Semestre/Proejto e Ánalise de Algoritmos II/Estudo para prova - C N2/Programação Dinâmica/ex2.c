#include <stdio.h>

void imprimirMatriz(int matriz[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", matriz[i][j]);
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
  return 0;
}

int programacao_dinamica(int n, int matriz[4][4], int resultante[4][4]) {
  int j = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (j = 0; j <= i; j++) {
      if (i == n - 1) {
        resultante[i][j] = matriz[i][j];
        // printf("s[%d][%d] = %d\n", i, j, resultante[i][j]);
      } else {
        resultante[i][j] = matriz[i][j] + maior(resultante[i + 1][j], resultante[i + 1][j + 1]);
        // printf("s[%d][%d] = %d\n", i, j, resultante[i][j]);
      }
    }
  }
  return resultante[0][0];
}

int main(){
    int matriz[4][4];
    int resultante[4][4];

    int n = 4;

    matriz[0][0] = 7;
    matriz[0][1] = 0;
    matriz[0][3] = 0;  
    matriz[1][0] = 3;
    matriz[1][1] = 8;
    matriz[2][0] = 8;
    matriz[2][1] = 1;
    matriz[2][2] = 0;
    matriz[2][3] = 0;
    matriz[3][0] = 2;
    matriz[3][1] = 7;
    matriz[3][2] = 4;
    matriz[3][3] = 4;

    imprimirMatriz(matriz);
    printf("\nProgramacao Dinamica --> Resultado: %d", programacao_dinamica(n, matriz, resultante));

    return 0;
    }