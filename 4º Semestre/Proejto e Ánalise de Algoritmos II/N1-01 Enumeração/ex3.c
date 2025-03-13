#include <stdbool.h>
#include <stdio.h>

void id_aluno(){
  printf("\nProf. Charles Boulhosa Rodamilans - TURMA: 04N\nDisciplina: Projeto e Analise de Algoritmos II\n");
  printf("\nAluno\n--------------------------------------------------\n");
  printf("Nome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("--------------------------------------------------\n");
}

bool funcao3(int vetor[], int tam_vetor, int subsequencia[], int tam_subsequencia){
  int posicao_vetor, posicao_subsequencia;
  posicao_vetor = 0;
  posicao_subsequencia = 0;
  while (posicao_vetor < tam_vetor && posicao_subsequencia < tam_subsequencia) {
    if (vetor[posicao_vetor] == subsequencia[posicao_subsequencia]) {
      posicao_subsequencia += 1;
    }
    posicao_vetor += 1;
  }

  if (posicao_vetor >= tam_vetor){
    printf("\nRESPOSTA: FALSE");
    return false; // FALSE
  } else {
    printf("\nRESPOSTA: TRUE");
    return true; // TRUE
  }
}

int main(){
  int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int subsequencia[3] = {4, 2, 9};

  id_aluno();
  funcao3(vetor, 10, subsequencia, 3);
  return 0;
}