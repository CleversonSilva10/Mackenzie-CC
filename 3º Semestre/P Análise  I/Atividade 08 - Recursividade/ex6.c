#include <stdio.h>
#include <stdbool.h>

int menor(int v[], int tamanho, int indice){
    if (tamanho == 0){
        return v[indice];
    }else{
        if (v[tamanho-1]<v[indice]){
            return menor(v, tamanho-1, tamanho-1);
        }else{
            return menor(v, tamanho-1, indice);
        }
    }
}

int maior(int v[], int tamanho, int indice){
    if (tamanho == 0){
        return v[indice];
    }else{
        if (v[tamanho-1]>v[indice]){
            return maior(v, tamanho-1, tamanho-1);
        }else{
            return maior(v, tamanho-1, indice);
        }
    }
}

int somavetor(int v[], int tamanho){
    if (tamanho == 0){
        return 0;
    }else{
        return v[tamanho-1] + somavetor(v, tamanho-1);
    }
}

int somapares(int v[], int tamanho){
    if (tamanho == 0){
        return 0;
    }else{
        if (v[tamanho-1]%2 == 0){
            return v[tamanho-1] + somapares(v, tamanho-1);
        }
        else{
            return 0 + somapares(v, tamanho-1);
        }
    }
}

bool busca_linear(int v[], int tamanho, int busca){
    if (tamanho == 0){
        return false;
    } else if(v[tamanho-1] == busca){
        return true;
    }else{
        return busca_linear(v, tamanho-1, busca);
    }
    
}



int main(){
    int i, *v, tamanho, busca;

    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");    

    printf("\nDigite o tamanho do vetor: "); scanf("%d", &tamanho);
    v = malloc(tamanho*sizeof(int));

    printf("\nPreencha o vetor\n\n");

    for (i = 0; i<tamanho; i++){
        printf("%d - Valor: ", i+1); scanf("%d", v+i);
    }
    
    printf("\nMaior elemento: %d", maior(v, tamanho, 0));
    printf("\nMenor elemento: %d", menor(v, tamanho, 0));
    printf("\nSoma dos elementos: %d", somavetor(v, tamanho));
    printf("\nSoma dos elementos pares: %d", somapares(v, tamanho));
    
    printf("\n\nQual número deseja buscar?: "); scanf("%d", &busca);
    printf("\nSoma dos elementos pares: %d", busca_linear(v, tamanho, busca));


}