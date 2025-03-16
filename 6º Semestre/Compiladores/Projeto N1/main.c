#include "implentacao.h"

// Identificador -> Letra_Minuscula(Letra_Minuscula | Digito)*
// NUMERO -> DIGITO+.DIGITO+

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico

int main(){
    Aluno();
    TInfoAtomo info_atomo;

    //entrada = lerArquivo("teste.txt");    
    
    //TESTES
    //entrada = "12.4"; RECONHECE NUMERO
    entrada = "abbbaa   \n _avabaa aaaaaaaaaaaaaaaaa _avabaa"; // RECONHECE ATOMO
    //entrada = "aaaaaaaaaaaaaaaaa"; // RECONHECE ATOMO
    //entrada = '_avabaa';


    //entrada = "var1 _var1 _b1ar _var2 _var3 _var4 _var5 _var6 12.4 12.4 12.4 12.4 12.4//aaabbbaa//\n\n/*aaaa*/";
    //entrada = "_var6 12.4 12.4 12.4 12.4 12.4//aaabbbaa//\n\n/*aaaa*/var1 _var1 _b1ar _var2 _var3 _var4 _var5";
    //entrada = "12.4 12.4 12.4 12.4 12.4\n\n12.4"; // ESTA OK
    //entrada = "_main\nmain\nint\nchar void writeint charaaa bbbb ccccccccccccccccc\na;";
    //entrada = "12.4\naaa\n\n//asdasdasd//\nvar1/*asdasdasd*/";
    printf("\nIniciando leitura do arquivo...\n");

    do{
        info_atomo = obter_atomo(); // Obter_atomo == Analisador Lexico
    }while(info_atomo.atomo != ERRO && info_atomo.atomo != EOS);
        printf("\n\nFim da analise lexica!\n\n");
        
    return 0;
}