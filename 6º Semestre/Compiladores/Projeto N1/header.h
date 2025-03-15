#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void Aluno();
;//extern char *entrada;
char *strAtomo[]={"ERRO", "IDENTIFICADOR", "NUMERO", "COMENTARIO","EOS"};

typedef enum{
    ERRO,
    IDENTIFICADOR,
    NUMERO,
    COMENTARIO,
    EOS
}TAtomo;

typedef struct{
    TAtomo atomo;
    int linha;
    float atributo_numero;
    char atributo_ID[16];
}TInfoAtomo;

TInfoAtomo obter_atomo();
TInfoAtomo reconhecer_id();
TInfoAtomo reconhece_comentario();
TInfoAtomo reconhecer_num();


