#include <stdio.h>

int leitura_txt(int **matriz, int linha, int coluna) {
  int i, j, aux_integer;
  FILE *arquivo;
  arquivo = fopen("ladrilho.txt", "r");

  if (arquivo != NULL) {
    for (i = 0; i < linha; i++) {
      for (j = 0; j < coluna; j++) {
        fscanf(arquivo, "%d", &aux_integer);
        matriz[i][j] = aux_integer;
      }
    }
    printf("\nInformações sobre txt:\n-------------------------------------\n");
    printf("Leitura realizada com sucesso!\n");
    printf("-------------------------------------\n");
    return 1;
  } else {
    printf("\nInformações sobre txt:\n-------------------------------------\n");
    printf("Leitura não foi realizada com sucesso!\n");
    printf("-------------------------------------\n");
    printf("Verifique se diretório está correto\n\n");
    return 0;
  }
}

void gerar_resposta(int **matriz_resposta, int linha, int coluna) {
  int i, j, contador = 1, ultima_l = linha - 1;
  for (i = 0; i < linha; i++) {
    for (j = 0; j < coluna; j++) {
      matriz_resposta[i][j] = contador;
      contador++;
    }
  }
  matriz_resposta[ultima_l][ultima_l] = 0;
}

int ganhou(int **matriz, int **matriz_resposta, int linha, int coluna) {
  int i, j, contador = 0, ultima_l = linha - 1, ultima_c = coluna - 1;
  for (i = 0; i < linha; i++) {
    for (j = 0; j < coluna; j++) {
      if (matriz[i][j] != matriz_resposta[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}