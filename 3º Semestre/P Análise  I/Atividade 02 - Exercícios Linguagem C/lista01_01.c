#include <stdio.h>

int main() {
    int num_1, i, resposta = 0;

  printf("\nRealizado 19/08/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
  printf("\nExercicio 1: Preencha uma lista com 10 números digitados pelo usuário e exiba: ");
  printf("\n------------------------\n");
  
  printf("Digite o valor desejado: ");
  scanf("%d", &num_1);

  if (num_1<=1){
    printf("O valor: %d não é primo");
  }
  
  if(num_1 >= 2){
    for (i = 1; i<=num_1; i++){
        if (num_1%i == 0){
            resposta++;
        }
    }
  }
  if (resposta == 2){
    printf("O número selecionado %d é primo", num_1);
    printf("\nTRUE");
  }else{
    printf("O número selecionado %d não é primo", num_1);
    printf("\nFALSE");
  }
}