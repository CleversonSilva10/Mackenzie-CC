#include <stdbool.h>
#include <stdio.h>

void id_aluno(){
  printf("\nProf. Charles Boulhosa Rodamilans - TURMA: 04N\nDisciplina: Projeto e Analise de Algoritmos II\n");
  printf("\nAluno\n--------------------------------------------------\n");
  printf("Nome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("--------------------------------------------------\n");
}

int funcao5(int vetor[], int tam_vetor){
    int i; int cont = 0;
    for (i = 0; i<tam_vetor; i++){
        if (vetor[i] != vetor[i+1]){
            cont +=1;
        }
    }
    return cont;
}

int main(){
    id_aluno();
    int vetor1[11] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};
    int vetor2[9] = {3, -1, -1, -1, 12, 12, 12, 3, 3};
    printf("Vetor 1 = %d\n", funcao5(vetor1, 11));
    printf("Vetor 2 = %d\n", funcao5(vetor2, 9));
}