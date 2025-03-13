#include <stdio.h>

int recursao(int n){
    if (n <= 10)
        return n * 2;
    else
        return recursao(recursao(n/3));
}

int main(){
    int n;

    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");    

    printf("\nDigite o valor de N: "); scanf("%d", &n);
    printf("\nResultado: %d", recursao(n));
}