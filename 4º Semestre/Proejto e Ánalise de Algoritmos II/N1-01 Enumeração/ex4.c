#include <stdbool.h>
#include <stdio.h>

void id_aluno(){
  printf("\nProf. Charles Boulhosa Rodamilans - TURMA: 04N\nDisciplina: Projeto e Analise de Algoritmos II\n");
  printf("\nAluno\n--------------------------------------------------\n");
  printf("Nome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("--------------------------------------------------\n");
}

bool funcao4(int vetor[], int tam_vetor, int sequencia[], int tam_sequencia){
    int i; int j = 0; int cont = 0;
    for (i = 0; i<tam_vetor; i++){
        if (vetor[i] == sequencia[j]){
            j++; cont += 1;
            if (vetor[i+1] != sequencia[j]){
                if (cont == tam_sequencia){
                    printf("É um segmento de vetor: TRUE");
                    return true;                    
                }else{
                    printf("É um segmento de vetor: FALSE");
                    return false;
                }
            }
        }
    }
    return false;
}

int main(){
    int vetor[10] = {1, 2, 3, 4, 5, 6 , 7, 8, 9, 10};
    int sequencia[3] = {4, 5, 6};

    id_aluno();
    funcao4(vetor, 10, sequencia, 3);
}