#include "implentacao.h"

// Identificador -> Letra_Minuscula(Letra_Minuscula | Digito)*
// NUMERO -> DIGITO+.DIGITO+

// gcc main.c -Wall -Og -g -o MiniAnalisadorLexico

int main(){
    Aluno();
    TInfoAtomo info_atomo;

    //entrada = lerArquivo("teste.txt");    
    //entrada = "12.4";
    //entrada = "var1 _var1 _b1ar _var2 _var3 _var4 _var5 _var6 12.4 12.4 12.4 12.4 12.4//aaabbbaa//\n\n/*aaaa*/";
    //entrada = "_var6 12.4 12.4 12.4 12.4 12.4//aaabbbaa//\n\n/*aaaa*/var1 _var1 _b1ar _var2 _var3 _var4 _var5";
    //entrada = "12.4 12.4 12.4 12.4 12.4\n\n12.4";
    entrada = "main aaa bbbb ccccccccccccccccc";
    //entrada = "12.4\naaa\n\n//asdasdasd//\nvar1/*asdasdasd*/";
    printf("\nIniciando leitura do arquivo...\n");

    do{ 
        info_atomo = obter_atomo(); // Obter_atomo == Analisador Lexico
        if(info_atomo.atomo == IDENTIFICADOR)
            printf("\n%03d# %s | %s", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_ID);

        if(info_atomo.atomo == NUMERO)
            printf("\n%03d# %s | %f", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_numero);

        if(info_atomo.atomo == COMENTARIO)
        printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

        if(info_atomo.atomo == ERRO)
        printf("\n%03d# %s | ", info_atomo.linha, strAtomo[info_atomo.atomo]);

        if(info_atomo.atomo == MAIN)
        printf("\n%03d# %s | %s", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_ID);
    
    }while(info_atomo.atomo != ERRO && info_atomo.atomo != EOS);
        printf("\nFim da analise lexica!\n\n");
        
    return 0;
}