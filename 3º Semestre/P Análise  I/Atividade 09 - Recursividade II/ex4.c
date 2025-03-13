#include <stdio.h>

int soma(int n){
    if (n%10 == n)
        return n;
    return (soma(n/10)+(n%10));
}

int main(){
    int n;
        printf("------------------------------------------------------");
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");
    printf("------------------------------------------------------");
    
    printf("\n\nDigite o valor: "); scanf("%d", &n);
    printf("Resultado: %d", soma(n));
}