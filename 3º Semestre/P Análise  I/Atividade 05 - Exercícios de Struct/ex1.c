#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[20];
    int tia;
    float nota_1;
    float nota_2;
};

void menu(){
    printf("\n\n-----------------MENU-------------------\n");
    printf("1 - Cadastrar os alunos\n");
    printf("2 - Mostrar todos os alunos cadastrados\n");
    printf("3 - Finalizar o programa!\n");
    printf("----------------------------------------\n");
}

int main(){
  int i, tam_aluno; char nome[20]; int tia, opcao, terminar; float nota_1, nota_2, media;

  printf("\nRealizado 04/09/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
  printf("\nExercicio 1");
  printf("\n------------------------\n");

  printf("\nQuantos alunos você deseja cadastrar?: ");
  scanf("%d", &tam_aluno);
  struct aluno p[tam_aluno];
    while (terminar != 3){
        menu(); printf("\nQual opção desejada?: "); scanf("%d", &opcao);
        if (opcao == 1){
            for (i = 0; i<tam_aluno; i++){
                printf("\n%d - Aluno", i+1);
                printf("\n----------------------------------------");
                printf("\nDigite o nome: "); scanf("%s", &p[i].nome);
                printf("Digite o TIA: "); scanf("%d", &p[i].tia);
                printf("Digite o Nota 1: "); scanf("%f", &p[i].nota_1);
                printf("Digite o Nota 2: "); scanf("%f", &p[i].nota_2);
                printf("----------------------------------------\n");
            }
        }
        if (opcao == 2){
            printf("\n\nApresentando todos os alunos!\n");
            for (i = 0; i<tam_aluno; i++){
                printf("\n%d - Aluno", i+1);
                printf("\n----------------------------------------");
                printf("\nNome: %s", p[i].nome);
                printf("\nTIA: %d", p[i].tia);
                media = (p[i].nota_1+p[i].nota_2)/2;
                printf("\nMédia Final: %.2f", media);
                printf("\n----------------------------------------\n");
            }
        }
        if (opcao == 3){
            printf("Programa finalizado! Até breve");
            terminar = 3;
        }   
    }
}