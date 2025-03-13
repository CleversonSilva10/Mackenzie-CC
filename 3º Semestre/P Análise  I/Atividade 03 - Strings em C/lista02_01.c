#include <stdio.h>
#include <string.h>



int main(){
    char string1[30], string2[30], string3[30];
    printf("\nRealizado 20/08/2022");
    printf("\n------------------------\n");
    printf("Nome Cleverson Pereira da Silva - TIA 32198531");
    printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
    printf("\n------------------------\n");

    printf("\nDigite a primeira palavra: "); scanf("%s", &string1);
    printf("Digite a segunda palavra: "); scanf("%s", &string2);
    printf("Digite a terceira palavra: "); scanf("%s", &string3);

    if(strcmp(string1, string2) >= 0){
        if(strcmp(string2, string3) >=0){
            printf("%s", string3);
        }else{
            printf("%s", string2);
        }
    }
    if(strcmp(string1, string2) <= 0){
        if(strcmp(string1, string3) <=0){
            printf("%s", string1);
        }else{
            printf("%s", string3);
        }
    }
}