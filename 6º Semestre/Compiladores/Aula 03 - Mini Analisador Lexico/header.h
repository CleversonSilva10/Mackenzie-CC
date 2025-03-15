#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

extern char *entrada;

char *strAtomo[]={"ERRO", "IDENTIFICADOR", "NUMERO", "EOS"};

typedef enum{
    ERRO,
    IDENTIFICADOR,
    NUMERO,
    EOS
}TAtomo;

typedef struct{
    TAtomo atomo;
    int linha;
    float atributo_numero;
    char atributo_ID[16];
}TInfoAtomo;

void Aluno();
TInfoAtomo obter_atomo();
TInfoAtomo reconhecer_id();
TInfoAtomo reconhecer_num();

