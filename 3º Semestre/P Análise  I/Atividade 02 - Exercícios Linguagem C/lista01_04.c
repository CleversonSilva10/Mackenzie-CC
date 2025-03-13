#include <stdio.h>

int main() {
  int preencher, i, vetor[10], opcao, maior, menor, soma = 0, cont = 0;
  float media;

  printf("\nRealizado 19/08/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
  printf("\nExercicio 4: Preencha uma lista com 10 números digitados pelo usuário e exiba: ");
  printf("\n------------------------\n");

// Preenchimento dos dados ///

  printf("\nPreencha os dados\n");
  for (preencher = 1; preencher<=10; preencher++){
    printf("%d - Digite valor: ", preencher);
    scanf("%d", &vetor[preencher]);
  }

// MENU //

  printf("\n__ MENU __n1 -\n1 - O maior número da lista\n");
  printf("2 - O menor número da lista\n");
  printf("3 - A quantidade de números pares da lista\n");
  printf("4 - A média dos números contidos na lista\n");
  printf("5 - Todos os números menores do que a média calculada no item anterior\n");

// Opções //

    printf("\nDigite a opção desejada: ");
    scanf("%d", &opcao);

// Opção 1 //
  if(opcao == 1){
    maior = vetor[0];
    for (i = 0; i<=10; i++){
      if (vetor[i]>maior){
        maior = vetor[i];
      }
    }
  printf("O maior valor é %d", maior);
  }
// Opção 2 //
  if(opcao == 2){
    menor = vetor[0];
    for (i = 0; i<=10; i++){
      if (vetor[i]<menor){
        menor = vetor[i];
      }
    }
  printf("O menor valor é: %d", menor);
  }
// Opção 3 //
  if (opcao == 3){
    for (i = 0; i<=10; i++){
        if (vetor[i]%2 == 0){
          cont++;
        }
    }
  printf("Quantidade de números pares é: %d", cont-1);
  }
// Opção 4 //
  if (opcao == 4){
    for (i = 0; i<=10; i++){
      soma = soma+vetor[i];
    }
    media = soma/10;
    printf("A média é: %.1lf", media);
  }

// Opção 5 //
    if (opcao == 5){
        for (i = 0; i<=10; i++){
            soma = soma+vetor[i];
        }
        media = soma/10;
        for (i = 1; i<10; i++){
            if(vetor[i]<media){
                printf("%d\n", vetor[i]);
            }
        }
    }
}