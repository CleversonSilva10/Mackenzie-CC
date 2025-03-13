#include <stdio.h>
#include <stdbool.h>

int main(){
    int tamanho, *vetor, i, *num_atual, chave, menor, h, valor, cont, j, opcao, terminar, met_ordenacao, aux; bool validacao;
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");


    printf("\nDigite o tamanho do vetor desejado: "); scanf("%d", &tamanho);
    vetor = malloc(tamanho*sizeof(int));
    printf("Alocação realizada com sucesso!\n"); 
    
    while(terminar != 8){
        printf("\n\n --------- MENU ----------- \n");
        printf("1 - Inserir os elementos dentro do vetor\n");
        printf("2 - Ordenar os elementos\n");
        printf("8 - Finalizar o programa!\n");
        printf("--------------  ------------------ \n");
        printf("\nDigite opcao desejada: "); scanf("%d", &opcao);        
        if (opcao == 1){
            printf("\nInsira os elementos desejados\n\n");
            for (i = 0; i<tamanho; i++){
                printf("%d - Valor: ", i+1); scanf("%d", vetor+i);
            }
        }
        if (opcao == 2){
            printf("\n-------- Métodos de ordenação ----------- ");
            printf("\n\n1 - Bubble Sort\n2 - Insertition Sort\n3 - Selection Sort\n4 - Shell Sort\n5 - Verificar");
            printf("\n\nQual deseja?: "); scanf("%d", &met_ordenacao);
            if (met_ordenacao == 1){ // BUBBLE SORT //
                for (i = 0; i<tamanho; i++){
                    for (j = 0; j<tamanho-1; j++){
                        if(*(vetor+j) > *(vetor+j+1)){
                            aux = *(vetor+j);
                            *(vetor+j) = *(vetor+j+1);
                            *(vetor+j+1) = aux;
                        }
                    }
                }
                for (i = 0; i<tamanho; i++){
                    printf("\n%d - Valor: %d", i+1, *(vetor+i));
                }
            }
            if (met_ordenacao == 2){ // Insertion Sort //
                for (i = 1; i<tamanho; i++) {
                    chave = *(vetor+i);
                    j = i - 1;
                    while (j >= 0 && *(vetor+j) > chave) {
                        *(vetor+j+1) = *(vetor+j);
                        j = j - 1;
                    }
                    *(vetor+j+1) = chave;
                }

                for (i = 0; i<tamanho; i++){
                    printf("\n%d - Valor: %d", i+1, *(vetor+i));
                }                
            }
            if (met_ordenacao == 3){ // Selection Sort //
                for (i = 0; i<tamanho-1; i++){
                    menor = i;
                    for (j = i+1; j<tamanho; j++){
                        if(*(vetor+menor)>*(vetor+j)){
                            menor = j;
                        }
                    }
                    if (i!=menor){
                        aux = *(vetor+i);
                        *(vetor+i) = *(vetor+menor);
                        *(vetor+menor) = aux; 
                    }
                }
                for (i = 0; i<tamanho; i++){
                    printf("\n%d - Valor: %d", i+1, *(vetor+i));
                }                    
            }
            if (met_ordenacao == 4){ // Shell Sort //
                h = 1;
                while(h < valor) {
                    h = 3*h+1;
                }
                while (h > 0) {
                    for(i = h; i<tamanho; i++) {
                        valor = *(vetor+i);
                        j = i;
                        while (j > h-1 && valor <= *(vetor+(j-h))){
                            *(vetor+j) = *(vetor+(j-h));
                            j = j - h;
                        }
                        *(vetor+j) = valor;
                    }
                    h = h/3;
                }
                for (i = 0; i<tamanho; i++){
                    printf("\n%d - Valor: %d", i+1, *(vetor+i));                
                }
            }
            if (met_ordenacao == 5){ // Verificação de ordenação //
                for(int i = 0; i < tamanho-1; i++){
                    if(*(vetor+i)>*(vetor+i+1)){
                        printf("Vetor não está ordenado!");
                    }
                }
            }
        }
        if (opcao == 8){
            printf("Programa finalizado, até breve!");
            terminar = 8;
        }
    }
}