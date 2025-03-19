#include "analisador_sintatico.h"

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico

// { REPETE VARIAS VEZES }
// [ OPCIONAL ]

int main(){
    Aluno();
    printf("\nIniciando leitura do arquivo...\n");
    
    entrada = ler_arquivo("Arquios_Teste/Arquivo_B.txt");

    // info_atomo = obter_atomo();
    // lookahead = info_atomo.atomo;
   
    do{
        info_atomo = obter_atomo();
    }while (info_atomo.atomo != ERRO || info_atomo.atomo != EOS);
        printf("FIM DO ANALISADOR LEXICO");

    return 0;
}
