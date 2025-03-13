#include <stdio.h>
#include <string.h>

char string[20];
char letra;
int a, tam, c;

int main(){
    printf("\nRealizado 20/08/2022");
    printf("\n------------------------\n");
    printf("Nome Cleverson Pereira da Silva - TIA 32198531");
    printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
    printf("\n------------------------\n");

    printf("\nDigite a palavra: "); scanf("%s", string);
    printf("Qual letra deseja remover?: "); scanf("%s", &letra);

    tam = strlen(string);
    for (a = 0, c = 0; a<tam; a++){
        if (string[a] != letra){
            string[c] = string[a];
            c++;
        }
    }
    string[c] = '\0';
    printf("A remoção da letra foi atualizada: %s", string);
    return 0;
}