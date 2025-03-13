#include <stdio.h>

int verifica(int num_1){
  int resposta = 0, i;
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
  }
}

int main() {
  int aux, num_1, num_2, i, j, primo, not_primo;
  printf("\nRealizado 19/08/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
  printf("\nExercicio 2");
  printf("\n------------------------\n");

	printf("Digite o primeiro numero: "); scanf("%d", &num_1);
  printf("Digite o segundo numero: "); scanf("%d", &num_2);

	if(num_1 > num_2){
		aux = num_1;
    num_1 = num_2;
    num_2 = aux;
  }

  for (i = num_1; i<num_2; i++){
    verifica(i);
    }
  }