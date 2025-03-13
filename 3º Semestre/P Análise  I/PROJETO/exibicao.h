#include <stdio.h>

void id_alunos() {
  printf("\nProf. Charles Boulhosa Rodamilans - TURMA: 03N\n\nProjeto N2 - O "
         "jogo da minha infância\n");
  printf("\nIntegrantes da "
         "dupla\n--------------------------------------------------\n");
  printf("Nome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("Nome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\n--------------------------------------------------\n");
}

void arquivo_nao_acessado() {
  printf("\n\n\nInformações sobre a leitura do "
         "arquivo:\n--------------------------------------\n");
  printf("O arquivo 'TXT' não foi lido corretamente!");
  printf("\n--------------------------------------\n");
}

void imprime(int **matriz, int linha, int coluna) {
  int i, j;
  printf("\n\n     MATRIZ - [%d] [%d]", linha, coluna);
  printf("\n-------------------------\n      ");
  for (i = 0; i < coluna; i++) {
    printf(" C%d   ", i);
  }
  printf("\n");
  for (i = 0; i < linha; i++) {
    printf("%dL | ", i);
    for (j = 0; j < coluna; j++) {
      if (matriz[i][j] >= 10) {
        printf(" [%d] ", matriz[i][j]);
      } else {
        printf(" [0%d] ", matriz[i][j]);
      }
    }
    printf("\n");
  }
  printf("--------------------------\n");
}

void menu() {
  printf("\n        MENU        ");
  printf("\n--------------------------\n");
  printf("1. Jogar uma partida - 'Jogo TXT'\n");
  printf("2. Gerador de resposta - Matriz Resposta\n");
  printf("3. Objetivo do jogo\n");
  printf("4. Lendo jogadas CSV\n");
  printf("5. Finalizar o jogo!");
  printf("\n--------------------------\n");
};

void posicao_inadequada() {
  printf("\n-------------------------------");
  printf("\nJogada inválida! Tente novamente!");
  printf("\n-------------------------------\n");
}

void jogada_efetuada() {
  printf("\n-------------------------------");
  printf("\nJogada efetuada com sucesso!");
  printf("\n-------------------------------\n");
}

void valor_inadequado() {
  printf("-------------------------------");
  printf("\nValor inválido! Tente novamente!");
  printf("\n-------------------------------\n");
}

void jogador_ganhou() {
  printf("-------------------------------");
  printf("\nParabéns! Você venceu o jogo!");
  printf("\n-------------------------------\n");
}

void objetivo() {
  printf("\n------------------\nObjetivo\n------------------\n\nOrdenar os "
  "quadrados, da esquerda para a direita e de cima para baixo, isto "
  "é,\nobter a disposição original dos contadores depois de terem sido "
  "aleatoriamente deslocados.\n\nFonte: Wikipedia\n\n");
}
