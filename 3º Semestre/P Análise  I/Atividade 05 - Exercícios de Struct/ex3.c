#include <stdio.h>
#include <stdlib.h>

struct mercado{
    char produto[50];
    int codigo;
    float preco;
};

void menu(){
    printf("\n\n-----------------MENU-------------------\n");
    printf("1 - Cadastrar os produtos\n");
    printf("2 - Lista de todos os produtos\n");
    printf("3 - Consultar o produto\n");
    printf("4 - Finalizar o programa!\n");
    printf("----------------------------------------\n");
}

int main(){
    char produto[20]; int i, codigo, qtdade_produto, input_codigo, terminar, opcao; float preco;

    printf("\nRealizado 04/09/2022");
    printf("\n------------------------\n");
    printf("Nome Cleverson Pereira da Silva - TIA 32198531");
    printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 2022");
    printf("\nExercicio 3");
    printf("\n------------------------\n");    

    printf("\nDigite o número de produtos que deseja cadastrar: "); scanf("%d", &qtdade_produto);
    struct mercado m[qtdade_produto];
    
    while (terminar != 4){
        menu(); printf("\nQual opção desejada?: "); scanf("%d", &opcao);
        if (opcao == 1){
            for (i = 0; i<qtdade_produto; i++){
                printf("\n%d - Produto", i+1);
                printf("\n----------------------------------------");
                printf("\nDigite o nome do produto: "); scanf("%s", &m[i].produto);
                printf("Digite o código: "); scanf("%d", &m[i].codigo);
                printf("Digite a preço R$: "); scanf("%f", &m[i].preco);
                printf("----------------------------------------\n");
            }
        }
        if (opcao == 2){
            printf("\n------------------PRODUTOS CADASTRADOS-------------------\n");
            for (i = 0; i<qtdade_produto; i++){
                printf("\nCódigo: %d - Produto: %s\n", m[i].codigo, m[i].produto);
            }
        }
        if (opcao == 3){
            printf("\n------------------ CONSULTA - PRODUTOS CADASTRADOS-------------------\n");
            printf("\nDigite código desejado: "); scanf("%d", &input_codigo);
            for (i = 0; i<qtdade_produto; i++){
                if (input_codigo == m[i].codigo){
                printf("\n------------------ CONSULTA - PRODUTOS ENCONTRADO-------------------\n");
                printf("\nNome do produto: %s \n", m[i].produto);
                printf("Preço do produto: R$%.2f \n", m[i].preco);
                }
            }
        }
        if (opcao == 4){
            printf("Programa finalizado!"); terminar = 4;
        }        
    }
}