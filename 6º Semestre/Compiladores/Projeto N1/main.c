#include "analisador_lexico.h"

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico

// { REPETE VARIAS VEZES }
// [ OPCIONAL ]

int main(){
    Aluno();
    printf("\nIniciando leitura do arquivo...\n");
    
    entrada = ler_arquivo("Arquivos de Teste/Arquivo_A.txt");

    do{
        info_atomo = obter_atomo(); // Obter_atomo == Analisador Lexico
    }while(info_atomo.atomo != ERRO && info_atomo.atomo != EOS);
        printf("\n\nFim da analise lexica!\n\n");
   
    return 0;
}
