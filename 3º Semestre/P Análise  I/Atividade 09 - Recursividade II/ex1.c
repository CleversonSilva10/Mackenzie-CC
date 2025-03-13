#include <stdio.h>

void binario(int n){
    if (n == 0){
        printf("%d", 0);
    }
    else{
        binario(n/2);
        printf("%d", n%2);
    }
}

int main(){
    int n;
    printf("------------------------------------------------------");
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");
    printf("------------------------------------------------------");

    printf("\nDigite o valor decimal desejado: "); scanf("%d", &n);
    printf("Resultado: "); binario(n);
}