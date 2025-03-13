#include <stdio.h>

int main(){
    int i, vetor[5], x, y, aux, r, opcao, a, b;
  printf("\nRealizado 20/08/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
  printf("\nEx 5: Escreva uma função que verifique se um vetor está em ordem crescente. \nCaso o vetor esteja em ordem crescente retorne True, e False caso contrário");
  printf("\n------------------------\n");
  printf("\nPreencha o vetor\n\n");

  for (i = 0; i<5; i++){
    printf("%d - Digite o número desejado: ", i+1);
    scanf("%d", &vetor[i]);
  }
  
  printf("\n__ Menu __\n");
  printf("\n1 - Verificar o vetor\n2 - Ordenar em ordem crescente\n3 - Ordernar em ordem decrescente\n");
  printf("\nDigite a opção desejado: ");
  scanf("%d", &opcao);

  if (opcao == 1){
    if (vetor[0]<vetor[1] && vetor[1]<vetor[2] && vetor[2]<vetor[3] && vetor[3]<vetor[4] && vetor[4]<vetor[5]){
      printf("O vetor está ordenado de forma crescente!\nTRUE");
    }else{
      printf("O vetor não está ordenado de forma crescente!\nFalse");
    }
  }

  if (opcao == 2){  
    for (x = 0; x<=5; x++){
      for (y = x; y<=5; y++){
        if (vetor[x]>vetor[y]){
          aux = vetor[x];
          vetor[x] = vetor[y];
          vetor[y] = aux;
        }
      }
    }
    printf("\nO vetor está ordenado devidamente de forma crescente: ");
    for (r = 0; r<5; r++){
      printf("|%d| ", vetor[r]);
    }
  }
  if (opcao == 3){  
    for (x = 0; x<=5; x++){
      for (y = x; y<=5; y++){
        if (vetor[x]<vetor[y]){
          aux = vetor[x];
          vetor[x] = vetor[y];
          vetor[y] = aux;
        }
      }
    }
    printf("\nO vetor está ordenado devidamente de forma decrescente: ");
    for (r = 0; r<5; r++){
      printf("|%d| ", vetor[r]);
    }
  }
}