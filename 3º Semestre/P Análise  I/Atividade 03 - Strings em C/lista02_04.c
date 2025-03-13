#include <stdio.h>
#include <string.h>


int main(){
    char string1[] = "ana", string2[20]; int i, n = 0;

    printf("\nRealizado 20/08/2022");
    printf("\n------------------------\n");
    printf("Nome Cleverson Pereira da Silva - TIA 32198531");
    printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
    printf("\n------------------------\n");

    printf("Verificação da palavra: \n\n");
    for (i = strlen(string1)-1; i>=0; i--){
        string2[n] = string1[i];
        n++;
    }
    
    string2[n] = '\0';
    
    if (strcmp(string2, string1) == 0){
        printf("Ele é um palindromo");
    }else{
        printf("Não é um palindromo");
    }
}

    