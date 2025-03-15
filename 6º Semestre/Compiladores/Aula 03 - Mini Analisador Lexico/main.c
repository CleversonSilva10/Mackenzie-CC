#include "implentacao.h"

// Identificador -> Letra_Minuscula(Letra_Minuscula | Digito)*
// NUMERO -> DIGITO+.DIGITO+

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico
// ./MiniAnalisadorLexico

char *entrada = "12.4\n\n\rvar1";

int main(){
    Aluno();
    TInfoAtomo info_atomo;
    do{ 
        info_atomo = obter_atomo();
        printf("%03d# %s | \n", info_atomo.linha,strAtomo[info_atomo.atomo]);
    }while(info_atomo.atomo != ERRO && info_atomo.atomo != EOS);
        printf("\nFim da analise lexica!\n\n");
    return 0;
}