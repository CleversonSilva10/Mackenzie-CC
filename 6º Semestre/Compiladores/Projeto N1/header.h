#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//extern char *entrada;

char *strAtomo[] = {
    "ERRO", 
    "IDENTIFICADOR", 
    "NUMERO", 
    "COMENTARIO",
    "EOS",
    "CHAR", 
    "ELSE", 
    "IF",
    "INT", 
    "MAIN",
    "READINT", 
    "VOID",
    "WHILE",
    "WRITEINT",
    "ABRE_PAR",
    "FECHA_PAR",
    "ABRE_CHAVE",
    "FECHA_CHAVE",
    "VIRGULA",
    "PONTO_VIRGULA",
    "ATRIBUICAO",
    "OPERADOR_COMPARACAO_OR",
    "OPERADOR_COMPARACAO_AND",
    "OPERADOR_COMPARACAO_MENOR_IGUAL",
    "OPERADOR_COMPARACAO_MENOR",
    "OPERADOR_COMPARACAO_MAIOR_IGUAL",
    "OPERADOR_COMPARACAO_MAIOR",
    "OPERADOR_COMPARACAO_DIFERENTE",
    "OPERADOR_SOMA",
    "OPERADOR_SUBTRACAO",
    "OPERADOR_MULTIPLICACAO",
    "OPERADOR_DIVISAO",
    "HEXADECIMAL",
    "TABELA_ASCII"
};

typedef enum{
    ERRO,
    IDENTIFICADOR,
    NUMERO,
    COMENTARIO,
    EOS,
    CHAR, 
    ELSE, 
    IF,
    INT, 
    MAIN,
    READINT, 
    VOID,
    WHILE,
    WRITEINT,
    ABRE_PAR,
    FECHA_PAR,
    ABRE_CHAVE,
    FECHA_CHAVE,
    VIRGULA,
    PONTO_VIRGULA,
    ATRIBUICAO,
    OPERADOR_COMPARACAO_OR,
    OPERADOR_COMPARACAO_AND,
    OPERADOR_COMPARACAO_MENOR_IGUAL,
    OPERADOR_COMPARACAO_MENOR,
    OPERADOR_COMPARACAO_MAIOR_IGUAL,
    OPERADOR_COMPARACAO_MAIOR,
    OPERADOR_COMPARACAO_DIFERENTE,
    OPERADOR_SOMA,
    OPERADOR_SUBTRACAO,
    OPERADOR_MULTIPLICACAO,
    OPERADOR_DIVISAO,
    HEXADECIMAL,
    TABELA_ASCII
}TAtomo;

typedef struct{
    TAtomo atomo;
    int linha;
    float atributo_numero;
    char Num_Tabela_ASCII;
    char atributo_ID[16];
    int quantidade_caracteres;
}TInfoAtomo;

char *ler_arquivo(const char *nome_arquivo);
void Apresentar_Atomo(TInfoAtomo info_atomo, const char *mensagem);
void Aluno();
TInfoAtomo CaracteresDemilitadores();
TInfoAtomo obter_atomo();
TInfoAtomo reconhecer_id();
TInfoAtomo reconhece_comentario();
TInfoAtomo reconhecer_num();
TInfoAtomo reconhecer_parentes();
TInfoAtomo reconhece_ponto_virgula();
TInfoAtomo reconhecer_chaves();
TInfoAtomo reconhece_Operando();
TInfoAtomo reconhece_Hexadecimal();
TInfoAtomo reconhece_Tabela_ASCII();
