#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void id_alunos() {
  printf("\n--------------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("--------------------------------------------------\n");
}

void forçabruta_LCS(char String1[], char String2[], int tam_String1, int tam_String2){
    int i = 0, j = 0;
    while (i < tam_String1 && j < tam_String2){
        if (String1[i] == String2[j]){
            printf("%c", String1[i]);
            j = j+1;
            if (j > tam_String2-1){
                j = 0;
                i = i+1;
            }
        }else{
            j = j+1;
        }
    }
    return; 
}

int main() {
  id_alunos();
  char String1[20];
  char String2[20];
  int tamanho_string1, tamanho_string2;
  
  printf("Informe a String1: ");
  scanf("%s", String1);
  tamanho_string1 = strlen(String1);
  printf("Informe a String2: ");
  scanf("%s", String2);
  tamanho_string2 = strlen(String2);
  
  forçabruta_LCS(String1, String2, tamanho_string1, tamanho_string2);
  
  return 0;
}