#include <stdio.h>

int result(int n){
    if (n == 1)
        return 2;
    else
        return 2 * result(n - 1);
}

int main(){
    int n;

    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");

    printf("\nDigite o valor de N: "); scanf("%d", &n);
    printf("\nResultado: %d", result(n));
}