#include <stdio.h>

int potencia(int a, int b){
    if (b == 0){
        return 1;
    }else if (b == 1){
        return a;
    }
    return a*potencia(a, b-1);
}

int main(){
    int a, b;

    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");

    printf("\nDigite o valor de A: "); scanf("%d", &a);
    printf("\nDigite o valor de B: "); scanf("%d", &b);
    printf("\nResultado: %d", potencia(a, b));
}