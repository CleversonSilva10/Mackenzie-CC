#include <stdio.h>
#include <string.h>

int comparaLetra(char *string, char compara){
  int qnt = 0;
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == compara) {
      qnt++;
    }
  }
  return qnt;
}

int main() {
  printf("\nRealizado 20/08/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
  printf("\n------------------------\n");

  char string[50];
  int a, c; printf("Digite a string:"); scanf("%s", string);
  int ocorrencia[strlen(string)];
  for (a = 0; a < strlen(string); a++) {
    ocorrencia[a] = comparaLetra(string, string[a]);
  }
  for (int i = 0; i < strlen(string); i++) {
    printf("%c - %d\n", string[i], ocorrencia[i]);
  }
}