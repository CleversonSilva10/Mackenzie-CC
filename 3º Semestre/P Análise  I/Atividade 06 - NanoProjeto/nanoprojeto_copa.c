#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct meualbum
{
    char nome[20];
    char sobrenome[20];
    char selecao[15];
    int codigo;
};

void menu(){
    printf("------------MENU------------\n");
    printf("1 - Cadastrar novas figurinhas\n");
    printf("2 - Estado do albúm\n");
    printf("3 - Realizar troca de figurinha - Álbum para outro albúm\n");
    printf("------------------------\n");
}

void menu2(){
    printf("\n1 - Mostrar figurinhas de uma única seleção - Já possui\n");
    printf("2 - Quantas restam para finalizar o álbum\n");
    printf("3 - Verificação - Figurinhas repetida por jogador\n"); 
    printf("4 - Quantas figurinhas já obteve\n"); 
}

int main() {
    char nome[20], sobrenome[20], selecao[15], escolherselecao[15]; int escolherjogador, codigo, i, opcao, opcao2, sair, qtdadef, maxjogador = 670, figrepetidas = 0;
    int naopreenchidas = 0, j, figpossue = 0, subst;
    printf("\nRealizado 06/09/2022 - Feito por:");
    printf("\n------------------------\n");
    printf("Nome Cleverson Pereira da Silva - TIA 32198531");
    printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
    printf("\n------------------------\n");
    printf("\nBem vindo - Álbum da Copa 2022\n\n");
    struct meualbum f[maxjogador];

    for (i = 0; i<maxjogador; i++){
        strcpy(f[i].nome, "NC");
        strcpy(f[i].sobrenome, "NC");
        strcpy(f[i].selecao, "NC");
        f[i].codigo = 999;
    }

    while (sair != 5){
        menu(); printf("\nDigite a opção desejada: "); scanf("%d", &opcao);
        if(opcao == 1){
            printf("\n---------- | Cadastro - Jogadores | ----------");
            printf("\n\nQuantos jogadores você deseja cadastrar?: "); scanf("%d", &qtdadef);
            for (i = 0; i<qtdadef; i++){
                printf("\n | %d - Jogador |\n\n", i+1);
                printf("Nome do jogador: "); scanf("%s", f[i].nome);
                printf("Sobrenome do jogador: "); scanf("%s", f[i].sobrenome);
                printf("Seleção: "); scanf("%s", f[i].selecao);
                printf("Código da figurinha: "); scanf("%d", &f[i].codigo); printf("\n");
            }
        }
        if (opcao == 2){
            printf("\n---------- | Estado do Álbum | ----------\n"); menu2();
            printf("\nQual opção você deseja?: "); scanf("%d", &opcao2); printf("\n");
            if(opcao2 == 1){
                printf("\nQual seleção você deseja visualizar?: "); scanf("%s", escolherselecao); printf("\n");
                for (i = 0; i<18; i++){
                    if (strcmp(escolherselecao, f[i].selecao) == 0){
                        printf("JOGADOR - %d\n", i+1);
                        printf("\n-----------------\n\n");
                        printf("|Nome: %s %s |\n", f[i].nome, f[i].sobrenome);
                        printf("|Seleção: %s |\n", f[i].selecao);
                        printf("|Código Figurinha: %d |\n", f[i].codigo);
                        printf("\n-----------------\n\n");
                    }
                }
            }
        }
        if(opcao2 == 2){
            for (i = 0; i<maxjogador; i++){
                if (f[i].codigo == 999){
                    naopreenchidas = naopreenchidas+1;
                }
            }
        printf("Números de figurinhas restantes: %d\n\n", naopreenchidas); naopreenchidas = 0;
        }

        if(opcao2 == 3){
            printf("Digite código do jogador desejado: "); scanf("%d", &escolherjogador); printf("\n");
            for (i = 0; i<maxjogador; i++){
                if (f[i].codigo == escolherjogador){
                    if (f[i].codigo != 999 && f[i].codigo > 0 && f[i].codigo <=670){
                        figrepetidas = figrepetidas+1;
                        if (figrepetidas > 1){
                            printf("Nome do Jogador: %s %s - Código: %d\n\n", f[i].nome, f[i].sobrenome, f[i].codigo);
                            printf("Números de figurinhas repetidas: %d\n\n", figrepetidas); figrepetidas = 0;
                        }
                    }
                }
            }
        }
        if (opcao2 == 4){
            for (i = 0; i<maxjogador; i++){
                if (f[i].codigo != 999){
                    figpossue = figpossue+1;
                }
            }
        printf("\nVocê já possue: %d Figurinhas\n\n", figpossue); figpossue = 0;
        }
        if(opcao == 3){
            printf("Digite código do jogador desejado: "); scanf("%d", &escolherjogador); printf("\n");
            for (i = 0; i<maxjogador; i++){
                if (f[i].codigo == escolherjogador){
                    if (f[i].codigo != 999 && f[i].codigo > 0 && f[i].codigo <=670){
                        figrepetidas = figrepetidas+1;
                        if (figrepetidas > 1){
                            printf("Nome do Jogador: %s %s - Código: %d\n\n", f[i].nome, f[i].sobrenome, f[i].codigo);
                            printf("Números de figurinhas repetidas: %d\n\n", figrepetidas);
                            printf("\n | Realizar a substituição | \n");
                            printf("\nNome do jogador: "); scanf("%s", f[i].nome);
                            printf("Sobrenome do jogador: "); scanf("%s", f[i].sobrenome);
                            printf("Seleção: "); scanf("%s", f[i].selecao);
                            printf("Código da figurinha: "); scanf("%d", &f[i].codigo); printf("\n");
                        }
                    }
                }
            }
        }
    }
}