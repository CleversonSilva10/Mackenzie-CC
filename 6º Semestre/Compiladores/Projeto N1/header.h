#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void Aluno();
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
    "WRITEINT"
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
    WRITEINT
}TAtomo;

typedef struct{
    TAtomo atomo;
    int linha;
    float atributo_numero;
    char atributo_ID[16];
    int quantidade_caracteres;
}TInfoAtomo;

void Apresentar_Atomo(TInfoAtomo info_atomo, const char *mensagem);
TInfoAtomo CaracteresDemilitadores(TInfoAtomo info_atomo);
TInfoAtomo obter_atomo();
TInfoAtomo reconhecer_id();
TInfoAtomo reconhece_comentario();
TInfoAtomo reconhecer_num();



