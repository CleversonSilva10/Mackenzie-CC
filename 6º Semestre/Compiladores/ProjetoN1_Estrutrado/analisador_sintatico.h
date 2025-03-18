#include "analisador_lexico.h"

void consome(TAtomo atomo ){
    if( lookahead == atomo ){
        info_atomo = obter_atomo();
        lookahead = info_atomo.atomo;
    }else if(info_atomo.atomo == EOS){
        printf("Nenhum erro sintatico");
    }
    else{
        printf("\nErro sintatico: esperado [%s] encontrado [%s]\n",strAtomo[atomo],strAtomo[lookahead]);
        exit(1);
    }
}

void program(){
    consome(VOID);
    consome(MAIN);
    consome(ABRE_PAR);
    consome(VOID);
    consome(FECHA_PAR);
    compound_stmt();
}

void compound_stmt() {
    consome(ABRE_CHAVE);
    if(lookahead == INT || lookahead == CHAR){
        var_decl();
        stmt();
        consome(FECHA_CHAVE);
    }
    consome(FECHA_CHAVE);
}

void var_decl() {
    type_specifier();
    var_decl_list();
    consome(PONTO_VIRGULA);
}

void type_specifier(){
    if (lookahead == INT){
        consome(INT);
    }else{
        consome(CHAR);
    }
}

void var_decl_list() {
    variable_id();
    while(1){
        if(lookahead == VIRGULA){
            consome(VIRGULA);
            variable_id();
        }else{
            break;
        }
    }    
}

void variable_id() {
    consome(IDENTIFICADOR);
    while (1){
        if(lookahead == ATRIBUICAO){
            consome(ATRIBUICAO);
            expr();
        }else{
            break;   
        }
    }
}

void stmt() {
    if(lookahead == ABRE_CHAVE){
        compound_stmt();
    }else if(lookahead == IDENTIFICADOR){
        assig_stmt();
    }else if(lookahead == IF){
        cond_stmt();
    }else if(lookahead == WHILE){
        while_stmt();
    }else if(lookahead == READINT){
        consome(READINT);
        consome(ABRE_PAR);
        consome(IDENTIFICADOR);
        consome(FECHA_PAR);
        consome(PONTO_VIRGULA);
    }else if (lookahead == WRITEINT){
        consome(WRITEINT);
        consome(ABRE_PAR);
        expr();
        consome(FECHA_PAR);
        consome(PONTO_VIRGULA);
    }
}

void assig_stmt() {
    consome(IDENTIFICADOR);
    if(lookahead == ATRIBUICAO){
        expr();
        consome(PONTO_VIRGULA);
    }
}

void cond_stmt() {
    consome(IF);
    consome(ABRE_PAR);
    expr();
    consome(FECHA_CHAVE);
    stmt();
    
    if(lookahead == ELSE){
        stmt();
    }
}

void while_stmt() {
    consome(WHILE);
    consome(ABRE_PAR);
    expr();
    consome(FECHA_PAR);
    stmt();
}

void expr() {
    conjunction();
    while(1){
        if(lookahead == OPERADOR_COMPARACAO_OR){
            consome(OPERADOR_COMPARACAO_OR);
            conjunction();
        }else{
            break;
        }
    }
}

void conjunction() {
    comparison();
    while(1){
        if(lookahead == OPERADOR_COMPARACAO_AND){
            consome(OPERADOR_COMPARACAO_AND);
            comparison();
        }else{
            break;
        }
    }
}

void comparison() {
    sum();
    if(lookahead == OPERADOR_COMPARACAO_MENOR ||
        lookahead == OPERADOR_COMPARACAO_MENOR_IGUAL ||
        lookahead == OPERADOR_COMPARACAO_IGUAL ||
        lookahead == OPERADOR_COMPARACAO_DIFERENTE ||
        lookahead == OPERADOR_COMPARACAO_MAIOR ||
        lookahead == OPERADOR_COMPARACAO_MAIOR_IGUAL){
            relation();
            sum();
    }
}

void relation(){
    if (lookahead == OPERADOR_COMPARACAO_MENOR) {
        consome(OPERADOR_COMPARACAO_MENOR);
    } else if (lookahead == OPERADOR_COMPARACAO_MENOR_IGUAL) {
        consome(OPERADOR_COMPARACAO_MENOR_IGUAL);
    } else if (lookahead == OPERADOR_COMPARACAO_IGUAL) {
        consome(OPERADOR_COMPARACAO_IGUAL);
    } else if (lookahead == OPERADOR_COMPARACAO_DIFERENTE) {
        consome(OPERADOR_COMPARACAO_DIFERENTE);
    } else if (lookahead == OPERADOR_COMPARACAO_MAIOR) {
        consome(OPERADOR_COMPARACAO_MAIOR);
    } else if (lookahead == OPERADOR_COMPARACAO_MAIOR_IGUAL) {
        consome(OPERADOR_COMPARACAO_MAIOR_IGUAL);
    }
}

void sum() {
    term();
    while (1){
       if(lookahead == OPERADOR_SOMA){
            consome(OPERADOR_SOMA);
            term();
       }else if(lookahead == OPERADOR_SUBTRACAO){
            consome(OPERADOR_SUBTRACAO);
            term();
       }else{
            break;
       }
    }
}

void term() {
    factor();
    while (1){
        if(lookahead == OPERADOR_MULTIPLICACAO){
             consome(OPERADOR_MULTIPLICACAO);
             factor();
        }else if(lookahead == OPERADOR_DIVISAO){
             consome(OPERADOR_DIVISAO);
             factor();
        }else{
             break;
        }
     }
 }

void factor() {
    if(lookahead == HEXADECIMAL){
        consome(HEXADECIMAL);
    }else if(lookahead == TABELA_ASCII){
        consome(TABELA_ASCII);
    } else if(lookahead == IDENTIFICADOR){
        consome(IDENTIFICADOR);
    }else if(lookahead == ABRE_PAR){
        consome(ABRE_PAR);
        expr();
        consome(FECHA_PAR);
    }
}