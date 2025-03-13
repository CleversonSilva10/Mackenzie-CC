#include <stdio.h>

int mdc(int a, int b){
    if (a == b)
        return a;
    else if (a>b){
        return mdc(a-b, b);
    }else{
        return mdc(b, a);
    }
}

int main(){
    int n1, n2;
    printf("------------------------------------------------------");
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");
    printf("------------------------------------------------------");

    printf("\n\nDigite o primeiro valor: "); scanf("%d", &n1);
    printf("Digite o segundo valor: "); scanf("%d", &n2);
    printf("\nResultado: %d", mdc(n1, n2));
}