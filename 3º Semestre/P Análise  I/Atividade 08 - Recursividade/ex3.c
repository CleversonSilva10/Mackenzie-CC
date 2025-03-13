#include <stdio.h>

int contagem, ligacao;
int fib(int n){
    if(n == 0){
            ligacao++;
            return 0;
    }else if(n == 1){
            ligacao++;
            contagem++;
            return 1;
    }else{
            ligacao++;
            return fib(n-1)+fib(n-2);
    }
}

int main(){
    int a = 1, b, resposta;
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");    
    
    for (int i = 0; i<a; ++i){
        contagem = 0;
        ligacao = 0;
        printf("FIB: "); scanf("%d", &b);
        resposta = fib(b);
        printf("FIB(%d) = %d Ligacoes = %d\n", b, ligacao-1, contagem);
    }
}