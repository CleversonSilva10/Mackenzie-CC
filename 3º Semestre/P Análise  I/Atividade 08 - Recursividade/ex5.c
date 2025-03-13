#include <stdio.h>

int produto(int a, int b){
    if (b == 1){
        return a*b;
    }
    if (b > 1){
        return a+produto(a, b-1);
    }
}

int main(){
    int a, b;

    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");

    printf("\nDigite o valor de A: "); scanf("%d", &a);
    printf("\nDigite o valor de B: "); scanf("%d", &b);
    printf("\nResultado: %d", produto(a, b));
}