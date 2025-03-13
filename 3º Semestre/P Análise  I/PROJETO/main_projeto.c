#include "exibicao.h"
#include "metodos.h"
#include "metodos_csv.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  id_alunos();
  int **matriz, **matriz_resposta, linha, coluna, i, j, opcao = 0, contador = 0;
  int tentativa_linha, tentativa_coluna, tentativa_valor, aux = 0, verifica_ganhou = 0;
  char posicao[1];  int aux1 = 0;

  // -------------- Os valores de linha e coluna para matriz dinâmica  ------------------ //
  printf("\n\nDigite número de linhas da matriz: "); scanf("%d", &linha);
  printf("Digite número de colunas da matriz: "); scanf("%d", &coluna); printf("\n");
  // -------------- Alocação feita para matriz ------------------ //
  
  // -------------- Alocação feita para matriz ------------------ //
  
  matriz = malloc(linha * sizeof(int));
  for (i = 0; i < linha; i++) {
    matriz[i] = malloc(coluna * sizeof(int));
  }

  matriz_resposta = malloc(linha * sizeof(int));
  for (i = 0; i < linha; i++){
    matriz_resposta[i] = malloc(coluna * sizeof(int));
  }
  // ----------------------------------------------------------- //

  while (opcao != 5) {
    menu();
    printf("\nQual opcão desejada: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
      if (leitura_txt(matriz, linha, coluna) == 1){
        printf("\nJogo começou!\n");

        // Gerar_resposta é uma forma de comparar se o jogador venceu o jogo!
        //-----------------------------------------------------------------//
        gerar_resposta(matriz_resposta, linha, coluna);
        //-----------------------------------------------------------------//

        while (verifica_ganhou != 1){
          //Esta função imprime e molde de visualização do jogo//
          imprime(matriz, linha, coluna);
          //-------------------------------------------------//

          printf("\nDigite a linha desejada: ");
          scanf("%d", &tentativa_linha);
          printf("\nDigite a coluna desejada: ");
          scanf("%d", &tentativa_coluna);
          printf("\n");

          if (tentativa_linha >= 0 && tentativa_linha <= linha && tentativa_coluna >= 0 && tentativa_coluna <= coluna) {
            if (matriz[tentativa_linha][tentativa_coluna] == 0) {
              printf("Posição escolhida: [%d][%d] = %d", tentativa_linha, tentativa_coluna, matriz[tentativa_linha][tentativa_coluna]);
              printf("\n\n-----------\nE = Esquerda | \nD = Direita  | \nB = Baixo    |\nC = Cima     |\n-----------\n");
              printf("\nQual a movimentação?: ");
              scanf("%s", posicao);

              // Movimentação dentro da matriz - Direita //
              if (strcmp(posicao, "D") == 0 || strcmp(posicao, "d") == 0) {
                aux1 = tentativa_coluna + 1;
                if (aux1 >= 0 && aux1 < coluna) { // Dentro do paramêtro da matriz
                  aux = matriz[tentativa_linha][tentativa_coluna];
                  matriz[tentativa_linha][tentativa_coluna] = matriz[tentativa_linha][aux1];
                  matriz[tentativa_linha][aux1] = aux;
                  jogada_efetuada();
                } else {
                  posicao_inadequada();
                }
              }
              // ------------------------------------------- // 
              
              // Movimentação dentro da matriz - Esquerda //
              if (strcmp(posicao, "E") == 0 || strcmp(posicao, "e") == 0) {
                aux1 = tentativa_coluna - 1;
                if (aux1 >= 0 &&
                    aux1 < coluna) { // Dentro do paramêtro da matriz
                  aux = matriz[tentativa_linha][tentativa_coluna];
                  matriz[tentativa_linha][tentativa_coluna] =
                      matriz[tentativa_linha][aux1];
                  matriz[tentativa_linha][aux1] = aux;
                  jogada_efetuada();
                } else {
                  posicao_inadequada();
                }
              }
              // ------------------------------------------- // 
              
              // Movimentação dentro da matriz - Baixo //
              if (strcmp(posicao, "B") == 0 || strcmp(posicao, "b") == 0) {
                aux1 = tentativa_linha + 1;
                if (aux1 >= 0 &&
                    aux1 < linha) { // Dentro do paramêtro da matriz
                  aux = matriz[tentativa_linha][tentativa_coluna];
                  matriz[tentativa_linha][tentativa_coluna] =
                      matriz[aux1][tentativa_coluna];
                  matriz[aux1][tentativa_coluna] = aux;
                  jogada_efetuada();
                } else {
                  posicao_inadequada();
                }
              }
              // ------------------------------------------- //

              // Movimentação dentro da matriz - Cima //     
              if (strcmp(posicao, "C") == 0 || strcmp(posicao, "c") == 0) {
                aux1 = tentativa_linha - 1;
                if (aux1 >= 0 &&
                  aux1 < linha) { // Dentro do paramêtro da matriz
                  aux = matriz[tentativa_linha][tentativa_coluna];
                  matriz[tentativa_linha][tentativa_coluna] = matriz[aux1][tentativa_coluna];
                  matriz[aux1][tentativa_coluna] = aux;
                  jogada_efetuada();
                }else{
                  posicao_inadequada();
                }
              }
              // ------------------------------------------- //
            }
          }
          if (ganhou(matriz, matriz_resposta, linha, coluna) == 1) {
            jogador_ganhou();
            verifica_ganhou = 1;
          }
        }
      }
    }

    if (opcao == 2) {
      gerar_resposta(matriz_resposta, linha, coluna);
      imprime(matriz_resposta, linha, coluna);
    }
    if (opcao == 3) {
      objetivo();
    }

    if (opcao == 4) {
      
      int tamanhoMatriz, tamanhoPassos;
      int **matriz = NULL;   // ponteiro que receberá a matriz de valores
      passos *Passos = NULL; // ponteiro da struct que receberá os passos
      FILE *input = fopen("ladrilhos.csv", "r"); // Inicia a conexão com o arquivo csv

      fscanf(input, "%d", &tamanhoMatriz); // Lê o tamanho da matriz quadrada
      matriz = malloc(tamanhoMatriz * sizeof(int)); // Aloca dinâmicamente as colunas da matriz
      for (int i = 0; i < tamanhoMatriz; i++) {
        matriz[i] = malloc(tamanhoMatriz * sizeof(int)); // Aloca dinâmicamente as linhas da matriz
        for (int j = 0; j < tamanhoMatriz; j++) { // Logo após isso insere os valores
          fscanf(input, "%d", &matriz[i][j]);
        }
      }

      fscanf(input, "%d", &tamanhoPassos); // Lê a quantidade de passos que o usuário vai passar
      Passos = malloc(tamanhoPassos * sizeof(passos)); // Inicia o vetor de structs que receberá os passos
      for (int i = 0; i < tamanhoPassos; i++) {
        fscanf( input, "%d %c", &Passos[i].valor, &Passos[i].direcao); // Lê os passos do usuário e insere na struct
      }

      printf("\nMatriz inicial:\n");
      imprime(matriz, linha, coluna); // Exibe a posição inicial da matriz
      if (resolveMatriz(Passos, matriz, tamanhoPassos,tamanhoMatriz)) { // Se o software conseguir resolver os passos e // no final a matriz estiver ordenada
        printf("\n\nPROBLEMA RESOLVIDO!!!\n\n"); 
        // Exibe mensagem indicando que // o usuário conseguiu  // completar o jogo // Caso contrário
      } else {                                  
        printf("\n\nEROOOOOOOO!!!"); 
        // Exibe mensagem indicando que o usuário // não conseguiu completar o jogo
      }
    }

    if (opcao == 5){
      printf("\n\n------------------------------------------\n");
      printf("Obrigado por jogar! Até breve");
      printf("\n------------------------------------------\n\n");
    }
  }
}



