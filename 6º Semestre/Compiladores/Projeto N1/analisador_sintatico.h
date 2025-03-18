#include <header.h>



void consome( TAtomo atomo ){
    if( lookahead == atomo ){
        info_atomo = obter_atomo();
        lookahead = info_atomo.atomo;
    }
    else{
        printf("\nErro sintatico: esperado [%s] encontrado [%s]\n",strAtomo[atomo],strAtomo[lookahead]);
        exit(1);
    }
}

void program(){
    
}

void compound_stmt() {
    // Implementação futura
}

void var_decl() {
    // Implementação futura
}

void type_specifier() {
    // Implementação futura
}

void var_decl_list() {
    // Implementação futura
}

void variable_id() {
    // Implementação futura
}

void stmt() {
    // Implementação futura
}

void assig_stmt() {
    // Implementação futura
}

void cond_stmt() {
    // Implementação futura
}

void while_stmt() {
    // Implementação futura
}

void expr() {
    // Implementação futura
}

void conjunction() {
    // Implementação futura
}

void comparison() {
    // Implementação futura
}

void relation() {
    // Implementação futura
}

void sum() {
    // Implementação futura
}

void term() {
    // Implementação futura
}

void factor() {
    // Implementação futura
}