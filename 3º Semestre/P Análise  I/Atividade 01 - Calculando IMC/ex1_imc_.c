#include <stdio.h>

int main() {
  float altura, peso, resultado;
  int escolha;

  /*Foi realizado os print's de todas as execuções e está documentado em um arquivo PDF, caso haja algum erro.*/

  printf("\nRealizado: 09/08/2022");
  printf("\n------------------------\n");
  printf("Nome: Cleverson Pereira da Silva - TIA: 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 2022/2");
  printf("\nExercicio 1: Calculando IMC");
  printf("\n------------------------\n");

  /* Menu */
  printf("\n----- MENU -----");
  printf("\n1 - Calcular o IMC\n");
  printf("2 - Sair do programa");
  printf("\n\nQual opção desejada?: ");
  scanf("%d", &escolha);

  while (escolha == 1){
    if (escolha == 1){
      /* Obtendo informações sobre o usuário */
      printf("\nDigite sua altura (Metro): ");
      scanf("%f", &altura);
      printf("Digite seu peso (KG): ");
      scanf("%f", &peso);
    
      /* Calculando o IMC do usúario */
      resultado = peso/(altura*altura);
      printf("\n------------------------\n");
      printf("IMC é: %.1lf", resultado);
      
      /*Classificando pelo resultado obtido*/
      if (resultado < 18.4){
        printf("\nClassificação: Abaixo do peso");
        printf("\n------------------------\n");
      }
      if (resultado >= 18.5 && resultado <= 24.9){
        printf("\nClassificação: Peso normal");
        printf("\n------------------------\n");
      }
      if (resultado >= 25.0 && resultado <= 29.9){
        printf("\nClassificação: Sobrepeso");
        printf("\n------------------------\n");
      }
      if (resultado >= 30.0 && resultado <= 34.9){
        printf("\nClassificação: Obesidade Grau 1");
        printf("\n------------------------\n");
      }
      if (resultado >= 35.0 && resultado <= 39.9){
        printf("\nClassificação: Obesidade Grau 2");
        printf("\n------------------------\n");
      }
      if (resultado >= 40.0){
        printf("\nClassificação: Obesidade Grau 3");
        printf("\n------------------------\n");
      }
    }
    printf("\n\nInsira o número: 1 - SIM / 2 - NÃO");
    printf("\nDeseja realizar novamente o cálculo?: ");
    scanf("%d", &escolha);
  }
  if (escolha == 2){
    printf("\nFinalizando o programa!\nAté breve!");
  }
  return 0;
}
  