#include "header.h"

int contalinhas = 1;

void Aluno(){
    printf("\n----------------------------------------\n");
    printf("Nome: Cleverson Pereira da Silva - RA: 10391119\n");
    printf("-------------------------------------------\n");
}

TInfoAtomo obter_atomo(){
    TInfoAtomo info_atomo;
    info_atomo.atomo = ERRO;
    
    while(*entrada == ' ' || *entrada == '\n' || *entrada == '\r' || *entrada == '\t'){
        entrada++;
        if(*entrada == '\n'){
            contalinhas++;
        }else if(*entrada == '\0'){
            info_atomo.atomo = EOS;
        }
    }
    if (isdigit(*entrada)){
        info_atomo = reconhecer_num();
    }
    else if (islower(*entrada)){
        info_atomo = reconhecer_id();
    }

    info_atomo.linha = contalinhas;
    
    return info_atomo;
}

TInfoAtomo reconhecer_id(){
    TInfoAtomo info_id;

    info_id.atomo = ERRO;

    if(isalpha(*entrada)){
        entrada++;
        goto Q1;
    }
    return info_id;
Q1:
    if(islower(*entrada) || isdigit(*entrada)){
        entrada++;
    }else if(isupper(*entrada)){
        return info_id;
    }
    
    info_id.atomo = IDENTIFICADOR;

    return info_id;
}

TInfoAtomo reconhecer_num(){
    TInfoAtomo info_num;
    info_num.atomo = ERRO;
    char str_num[20];
    char *inicio_num = entrada;
//Q0
    if(isdigit(*entrada)){
        entrada++;
        goto Q1;
    }
    return info_num;
Q1:
    if(isdigit(*entrada)){
        entrada++;
        goto Q1;
    }else if (*entrada == '.'){
        entrada++;
        goto Q2;
    }
    return info_num;
Q2:
    if(isdigit(*entrada)){
        entrada++;
        goto Q3;
    }
    return info_num;
Q3:
    if(isdigit(*entrada)){
        entrada++;
        goto Q3;
    }else if(isalpha(*entrada)){
        return info_num;
    }
    info_num.atomo = NUMERO;
    strncpy(str_num,inicio_num,entrada-inicio_num);
    str_num[entrada-inicio_num] = '\0';
    info_num.atributo_numero = atof(str_num);
    return info_num;
}