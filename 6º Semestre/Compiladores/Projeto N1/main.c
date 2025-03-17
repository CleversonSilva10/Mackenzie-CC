#include "implentacao.h"

// Identificador -> Letra_Minuscula(Letra_Minuscula | Digito)*
// NUMERO -> DIGITO+.DIGITO+

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico

int main(){
    Aluno();
    TInfoAtomo info_atomo;

    //TESTE B

    entrada = ler_arquivo("Arquivos de Teste/Arquivo_B.txt");
    printf("\nIniciando leitura do arquivo...\n");

    do{
        info_atomo = obter_atomo(); // Obter_atomo == Analisador Lexico
    }while(info_atomo.atomo != ERRO && info_atomo.atomo != EOS);
        printf("\n\nFim da analise lexica!\n\n");
   
    return 0;
}