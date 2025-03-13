#include <stdio.h>
#include <string.h>


int main(){
    int tam_string, i; char string1[] = "Cleverson";
    printf("\nRealizado 20/08/2022");
    printf("\n------------------------\n");
    printf("Nome Cleverson Pereira da Silva - TIA 32198531");
    printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
    printf("\n------------------------\n");

    tam_string = strlen(string1);

    for (i = 0; i<tam_string; i++){
        printf("%c - %x\n", string1[i], string1[i]);
    }
}