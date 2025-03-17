#include "implentacao.h"

// Identificador -> Letra_Minuscula(Letra_Minuscula | Digito)*
// NUMERO -> DIGITO+.DIGITO+

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico

// TESTE A
// TESTE B
// TESTE C
// TESTE D
//  TESTE E
// REVER TESTE F

int main(){
    Aluno();
    TInfoAtomo info_atomo;

    entrada = ler_arquivo("Arquivos de Teste/Arquivo_F.txt");
    printf("\nIniciando leitura do arquivo...\n");

    do{
        info_atomo = obter_atomo(); // Obter_atomo == Analisador Lexico
    }while(info_atomo.atomo != ERRO && info_atomo.atomo != EOS);
        printf("\n\nFim da analise lexica!\n\n");
   
    return 0;
}
