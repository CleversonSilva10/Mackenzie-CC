#include <stdio.h>

int main() {
    int x, y, res = 0;

  printf("\nRealizado 19/08/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
  printf("\n3 - Escreva um programa que receba um número inteiro N, \nesse número não contém o digito 0 (zero), e devolve N invertido, exemplo: se N igual 123 a resposta será 321.");
  printf("\n------------------------\n");
  
  printf("Digite o valor desejado: ");
  scanf("%d", &x);

    if(x>=0){
      do{
        y = x%10;
        printf("%d", y);
        x /= 10;
      }while (x!=0);
    }
    return 0;
    }