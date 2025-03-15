#include "implentacao.h"

// Identificador -> Letra_Minuscula(Letra_Minuscula | Digito)*
// NUMERO -> DIGITO+.DIGITO+

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico
// ./MiniAnalisadorLexico
////
int main(){
    Aluno();

    entrada = lerArquivo("arquivo_teste.txt");    
    
    //entrada = "/*asdasd*/\n//asdasd";
    TInfoAtomo info_atomo;

    printf("\nIniciando leitura do arquivo...\n\n");

    do{ 
        info_atomo = obter_atomo();
        printf("%03d# %s | \n", info_atomo.linha,strAtomo[info_atomo.atomo]);
    }while(info_atomo.atomo != ERRO && info_atomo.atomo != EOS);
        printf("\nFim da analise lexica!\n\n");
    return 0;
}