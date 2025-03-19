#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Aluno(){
    printf("\n----------------------------------------\n");
    printf("Nome: Cleverson Pereira da Silva - RA: 10391119\n");
    printf("-------------------------------------------\n");
}

char *entrada;
int contalinhas = 1;

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
    "OPERADOR_COMPARACAO_IGUAL",
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
    "INTCONST",
    "CHARCONST"
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
    OPERADOR_COMPARACAO_IGUAL,
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
    INTCONST,
    CHARCONST
}TAtomo;

typedef struct{
    TAtomo atomo;
    int linha;
    float atributo_numero;
    char Num_Tabela_ASCII;
    char atributo_ID[16];
    int quantidade_caracteres;
}TInfoAtomo;

TInfoAtomo info_atomo;
TAtomo lookahead;

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
TInfoAtomo reconhece_intconst();
TInfoAtomo reconhece_charconst();

void consome(TAtomo atomo);
void compound_stmt();
void var_decl();
void type_specifier();
void var_decl_list();
void variable_id();
void stmt();
void assig_stmt();
void cond_stmt();
void while_stmt();
void expr();
void conjunction();
void comparison();
void relation();
void sum();
void term();
void factor();

char *ler_arquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r"); // Abre o arquivo para leitura
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    char *conteudo = (char *)malloc(tamanho + 1);
    if (!conteudo) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return NULL;
    }

    fread(conteudo, 1, tamanho, arquivo);
    conteudo[tamanho] = '\0';

    fclose(arquivo); // Fecha o arquivo
    return conteudo; // Retorna o conteúdo lido
}

TInfoAtomo obter_atomo() {
    TInfoAtomo info_atomo;
    info_atomo.atomo = ERRO;

    if (*entrada == '\0') {
        info_atomo.atomo = EOS;
        return info_atomo;
    }

    info_atomo = CaracteresDemilitadores();

    if(*entrada == '\''){
        info_atomo = reconhece_charconst();
        return info_atomo;
    }

    if ((*entrada == '/' && *(entrada+1) == '/') || (*entrada == '/' && *(entrada+1) == '*')) {
        info_atomo = reconhece_comentario();
        return info_atomo;
    }

    if (*entrada == '0' && *(entrada+1) == 'x') {
        info_atomo = reconhece_intconst();
        return info_atomo;
    }

    if (*entrada == '='){ // Operação de ATRIBUIÇÃO
        info_atomo = reconhece_Operando();
        return info_atomo;
    }

    // Operação de Comparação 
    if  ((*entrada == '|' && *(entrada+1) == '|') || (*entrada == '&' && *(entrada+1) == '&') || 
        (*entrada == '=' && *(entrada+1) == '=') || (*entrada == '!' && *(entrada+1) == '=')){
        info_atomo = reconhece_Operando();
        return info_atomo;  
    }
    // Operação de comparação
    if ((*entrada == '<') || (*entrada == '<' && *(entrada+1) == '=') || (*entrada == '>') || (*entrada == '>' && *(entrada+1) == '=')){
            info_atomo = reconhece_Operando();
            return info_atomo;
        }

    // Operação Aritimetica
    if ((*entrada == '+') || (*entrada == '-') || (*entrada == '*') || (*entrada == '/')){
        info_atomo = reconhece_Operando();
        return info_atomo;
    }

    if ((*entrada == ';' || *entrada == ',')) {
        info_atomo = reconhece_ponto_virgula();
        return info_atomo;
    }

    if (*entrada == '(' || *entrada == ')'){
        info_atomo = reconhecer_parentes();
        return info_atomo;
    }

    if (*entrada == '{' || *entrada == '}'){
        info_atomo = reconhecer_chaves();
        return info_atomo;
    }

    if (isdigit(*entrada)) {
        info_atomo = reconhecer_num();
        return info_atomo;
    }

    if (isalpha(*entrada) || *entrada == '_') {
        info_atomo = reconhecer_id();
        return info_atomo;
    }

    return info_atomo; // ATOMO ERRO
}

TInfoAtomo CaracteresDemilitadores(){
    TInfoAtomo info_demilitadores;
    info_demilitadores.atomo = ERRO;

    while (*entrada == ' ' || *entrada == '\n' || *entrada == '\r' || *entrada == '\t') {
        if (*entrada == '\n') {
            contalinhas++;
        }        
        entrada++;
    }

    info_demilitadores.linha = contalinhas;
    //Chegando aqui estou com um caracter que precisa ser analisado
    return info_demilitadores; // Já saiu dos caracteres delimitadores
}

TInfoAtomo reconhece_charconst() {
    TInfoAtomo info_charconst;
    info_charconst.atomo = ERRO;  

    char temp[10];  
    int i = 0;

    if (*entrada == '\''){  
        entrada++;  

        while (isdigit(*entrada)) {  
           // temp[i++] = *entrada++;
           temp[i++] = *entrada;
           entrada++;  
        }

        temp[i] = '\0';
        info_charconst.Num_Tabela_ASCII = atoi(temp);  

        if (*entrada == '\'') {  
            entrada++; 
            info_charconst.atomo = CHARCONST;
            info_charconst.linha = contalinhas;
            Apresentar_Atomo(info_charconst, "NAO PRECISA DE MENSAGEM");
        }
    }

    return info_charconst;
}

// hexa → A|B|C|D|E|F
// intconst → 0x(hexa|digito)+

TInfoAtomo reconhece_intconst() {
    TInfoAtomo info_intconst;
    info_intconst.atomo = ERRO;
    info_intconst.atributo_numero = 0;

    int quantidade = 0;
    int resultado = 0;
    
    if (*entrada == '0' && *(entrada + 1) == 'x') { 
        entrada += 2;

        while (isdigit(*entrada) || (*entrada >= 'A' && *entrada <= 'F')) {
            entrada++;
            quantidade++;
        }
        entrada -= quantidade; 
        int expoente = quantidade - 1;
        
        for (int i = 0; i < quantidade; i++) {
            int valor;
            if (*entrada >= 'A' && *entrada <= 'F') {
                valor = (*entrada - 'A' + 10);
            } else {
                valor = (*entrada - '0');
            }

            resultado += valor * pow(16, expoente);
            expoente--;
            entrada++;
        }

        info_intconst.atomo = INTCONST;
        info_intconst.atributo_numero = resultado;
        info_intconst.linha = contalinhas++;
        
        Apresentar_Atomo(info_intconst, "");
        return info_intconst;
    }
    
    Apresentar_Atomo(info_intconst, "");
    return info_intconst;
}



TInfoAtomo reconhece_Operando() {
    TInfoAtomo info_operador;
    info_operador.atomo = ERRO;

    if (*entrada == '=' && *(entrada+1) != '=') {
        entrada++;
        info_operador.atomo = ATRIBUICAO;
    }

    if(*entrada == '=' && *(entrada+1) == '='){
        entrada += 2;
        info_operador.atomo = OPERADOR_COMPARACAO_IGUAL;
    }

    if(*entrada == '|' && *(entrada+1) == '|'){
        entrada += 2;
        info_operador.atomo = OPERADOR_COMPARACAO_OR;
    }

    if(*entrada == '&' && *(entrada+1) == '&'){
        entrada += 2;
        info_operador.atomo = OPERADOR_COMPARACAO_AND;
    }

    if(*entrada == '!' && *(entrada+1) == '='){
        entrada += 2;
        info_operador.atomo = OPERADOR_COMPARACAO_DIFERENTE;
    }

    if(*entrada == '<' && *(entrada+1) == '='){
        entrada += 2;
        info_operador.atomo = OPERADOR_COMPARACAO_MENOR_IGUAL;
    }
    
    if(*entrada == '<' && *(entrada+1) != '='){
        entrada++;
        info_operador.atomo = OPERADOR_COMPARACAO_MENOR;
    }

    if(*entrada == '>' && *(entrada+1) == '='){
        entrada += 2;
        info_operador.atomo = OPERADOR_COMPARACAO_MAIOR_IGUAL;
    }
    
    if(*entrada == '>' && *(entrada+1) != '='){
        entrada++;
        info_operador.atomo = OPERADOR_COMPARACAO_MAIOR;
    }

    if (*entrada == '+') {
        entrada++;
        info_operador.atomo = OPERADOR_SOMA;
    }
    
    if (*entrada == '-') {
        entrada++;
        info_operador.atomo = OPERADOR_SUBTRACAO;
    }
    
    if (*entrada == '*') {
        entrada++;
        info_operador.atomo = OPERADOR_MULTIPLICACAO;
    }
    
    if (*entrada == '/') {
        entrada++;
        info_operador.atomo = OPERADOR_DIVISAO;
    }

    info_operador.linha = contalinhas;
    Apresentar_Atomo(info_operador, "");
    return info_operador;
}



TInfoAtomo reconhecer_parentes(){
    TInfoAtomo info_parentes;
    info_parentes.atomo = ERRO;

    if(*entrada == '('){
        entrada++;
        info_parentes.atomo = ABRE_PAR;
    }else{
        entrada++;
        info_parentes.atomo = FECHA_PAR;
    }
    info_parentes.linha = contalinhas;
    Apresentar_Atomo(info_parentes, "MENSAGEM NAO NECESSARIA");
    return info_parentes;
}

TInfoAtomo reconhecer_chaves(){
    TInfoAtomo info_chaves;
    info_chaves.atomo = ERRO;

    if(*entrada == '{'){
        entrada++;
        info_chaves.atomo = ABRE_CHAVE;
    }else{
        entrada++;
        info_chaves.atomo = FECHA_CHAVE;
    }

    info_chaves.linha = contalinhas;
    Apresentar_Atomo(info_chaves, "MENSAGEM NAO NECESSARIA");
    return info_chaves;
}

TInfoAtomo reconhece_ponto_virgula(){
    TInfoAtomo info_pontoVirgula;
    info_pontoVirgula.atomo = ERRO;

    if (*entrada == ';'){
        info_pontoVirgula.atomo = PONTO_VIRGULA;
    }else if (*entrada == ','){
        info_pontoVirgula.atomo = VIRGULA;
    }

    info_pontoVirgula.linha = contalinhas;
    entrada++;
    Apresentar_Atomo(info_pontoVirgula, "");
    return info_pontoVirgula;
}


TInfoAtomo reconhece_comentario() {
    TInfoAtomo info_comentario;
    info_comentario.atomo = ERRO;

    if ((*entrada == '/' && *(entrada + 1) == '/') || (*entrada == '/' && *(entrada + 1) == '*')) {

        if (*entrada == '/' && *(entrada + 1) == '/') {
            entrada += 2; // Dentro do Comentário
            while (*entrada != '\n' && *entrada != '\0') { // Garantir que não saia por erro
                entrada++;
            }

            if (*entrada == '\n') {
                contalinhas++;
                entrada++;
            }

             // Para sair da linha de comentário
            info_comentario.linha = contalinhas;
            return info_comentario;
        }

        if (*entrada == '/' && *(entrada + 1) == '*') {
            entrada += 2; // Dentro do Comentário
            while (*entrada != '*' || *(entrada + 1) != '/') {
                if (*entrada == '\n') {
                    contalinhas++;
                } else if (*entrada == '\0') {
                    return info_comentario; // Comentário sem fechamento
                }
                entrada++;
            }
            entrada += 2; // Sair da área de comentários
            info_comentario.linha = contalinhas;
            return info_comentario;
        }
    }
    return info_comentario;
}


TInfoAtomo reconhecer_id() {
    TInfoAtomo info_id;
    info_id.atomo = ERRO;
    memset(info_id.atributo_ID, 0, sizeof(info_id.atributo_ID));
    int i = 0;

    while (*entrada != '\0' && *entrada != ' ' && *entrada != '\n' && *entrada != '(' && *entrada != ')'
            && *entrada != ';' && *entrada != ',' ){ //ANALISAR ESSA SITUACAO SE ESTA CORRETO

        if (!isalpha(*entrada) && !isdigit(*entrada) && *entrada != '_') {
            // SE NAO FOR LETRA, SE NAO FOR DIGITO, SE NAO FOR UNDERLINE
            info_id.linha = contalinhas;
            Apresentar_Atomo(info_id, "Atomo invalido");
            return info_id;
        }else{
            info_id.atributo_ID[i] = *entrada;
            i++;
            entrada++;
        }
    }
    
    info_id.atributo_ID[i] = '\0';
    info_id.quantidade_caracteres = i;
    info_id.linha = contalinhas;

    if (i > 15) {
        info_id.atomo = ERRO;
        Apresentar_Atomo(info_id, "ATOMO MAIOR DO QUE 15 CARACTERES");
        return info_id;
    }

    if (strcmp(info_id.atributo_ID, "char") == 0) {
        info_id.atomo = CHAR;
    } else 
        if (strcmp(info_id.atributo_ID, "else") == 0) {
            info_id.atomo = ELSE;
    } else 
        if (strcmp(info_id.atributo_ID, "if") == 0) {
            info_id.atomo = IF;
    } else 
        if (strcmp(info_id.atributo_ID, "int") == 0) {
            info_id.atomo = INT;
    } else 
        if (strcmp(info_id.atributo_ID, "main") == 0) {
            info_id.atomo = MAIN;
    } else 
        if (strcmp(info_id.atributo_ID, "readint") == 0) {
            info_id.atomo = READINT;
    } else 
        if (strcmp(info_id.atributo_ID, "void") == 0) {
            info_id.atomo = VOID;
    } else 
        if (strcmp(info_id.atributo_ID, "while") == 0) {
            info_id.atomo = WHILE;
    } else 
        if (strcmp(info_id.atributo_ID, "writeint") == 0) {
            info_id.atomo = WRITEINT;
    }else{
        info_id.atomo = IDENTIFICADOR;
    }

    Apresentar_Atomo(info_id, "NAO NECESSARIO MENSAGEM");
    return info_id;
}

TInfoAtomo reconhecer_num(){
    TInfoAtomo info_num;
    info_num.atomo = ERRO;
    char temp[50];
    int i = 0; 

    while(isdigit(*entrada) || *entrada == '.'){ 
        temp[i] = *entrada; 
        i++;
        entrada++;
    }
    
    temp[i] = '\0';
    info_num.atributo_numero = atof(temp);
    info_num.atomo = NUMERO;
    info_num.linha = contalinhas;

    Apresentar_Atomo(info_num, "Numero invalido");
    return info_num;
}

void Apresentar_Atomo(TInfoAtomo info_atomo, const char *mensagem){
    if(info_atomo.atomo == IDENTIFICADOR)
        printf("\n%03d# %s | %s", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_ID);

    if(info_atomo.atomo == NUMERO)
        printf("\n%03d# %s | %.2f", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_numero);

    if(info_atomo.atomo == COMENTARIO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == ERRO)
    printf("\n%03d# %s | %s", info_atomo.linha, strAtomo[info_atomo.atomo], mensagem);

    if(info_atomo.atomo == CHAR)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == ELSE)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == IF)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == INT)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);
    
    if(info_atomo.atomo == MAIN)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == READINT)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == VOID)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == WHILE)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == WRITEINT)
    printf("\n%03d# %s | PALAVRA RESERVADA", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == ABRE_PAR)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == FECHA_PAR)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == VIRGULA)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == PONTO_VIRGULA)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == ABRE_CHAVE)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == FECHA_CHAVE)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == ATRIBUICAO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);
    
    if(info_atomo.atomo == OPERADOR_COMPARACAO_IGUAL)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_COMPARACAO_OR)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_COMPARACAO_AND)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_COMPARACAO_MENOR_IGUAL)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_COMPARACAO_MENOR)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_COMPARACAO_MAIOR_IGUAL)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_COMPARACAO_MAIOR)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_COMPARACAO_DIFERENTE)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_SOMA)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_SUBTRACAO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_MULTIPLICACAO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_DIVISAO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == INTCONST)
    printf("\n%03d# %s | %.2f", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_numero);

    if(info_atomo.atomo == CHARCONST)
    printf("\n%03d# %s | %c", info_atomo.linha, strAtomo[info_atomo.atomo], (char)info_atomo.Num_Tabela_ASCII);
}

void consome(TAtomo atomo){
    // printf("\nconsome atomo: %s - PONTEIRO: %c\n", strAtomo[info_atomo.atomo], *entrada);
    // if( lookahead == atomo ){
    //     info_atomo = obter_atomo();
    //     lookahead = info_atomo.atomo;
    // }else{
    //     printf("\nErro sintatico: esperado [%s] encontrado [%s]\n",strAtomo[atomo], strAtomo[lookahead]);
    //     exit(1);
    // }
}

void program(){
    printf("\nENTREI - <program>");
    consome(VOID);
    consome(MAIN);
    consome(ABRE_PAR);
    consome(VOID);
    consome(FECHA_PAR);
    compound_stmt();
}

void compound_stmt() {
    printf("\nENTREI - <compound_stmt>");
    consome(ABRE_CHAVE);
    if(lookahead == INT || lookahead == CHAR){
        var_decl();
        stmt();
        consome(FECHA_CHAVE);
    }
    consome(FECHA_CHAVE);
}

void var_decl() {
    printf("\nENTREI - <var_decl>");
    type_specifier();
    var_decl_list();
    consome(PONTO_VIRGULA);
}

void type_specifier(){
    printf("\nENTREI - <type_specifier>");
    if (lookahead == INT){
        consome(INT);
    }else{
        consome(CHAR);
    }
}

void var_decl_list() {
    printf("\nENTREI - <var_decl_list>");
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
    printf("\nENTREI - <variable_id>");
    consome(IDENTIFICADOR);
    if(lookahead == ATRIBUICAO){
        consome(ATRIBUICAO);
        expr();
    }
}


void stmt() {
    printf("\nENTREI - <stmt>");
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
    printf("\nENTREI - <assig_stmt>");
    consome(IDENTIFICADOR);
    consome(ATRIBUICAO);
    expr();
    consome(PONTO_VIRGULA);
}

void cond_stmt() {
    printf("\nENTREI - <cond_stmt>");
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
    printf("\nENTREI - <while_stmt>");
    consome(WHILE);
    consome(ABRE_PAR);
    expr();
    consome(FECHA_PAR);
    stmt();
}

void expr() {
    printf("\nENTREI - <expr>");
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
    printf("\nENTREI - <conjunction>");
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
    printf("\nENTREI - <comparison>");
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
    printf("\nENTREI - <relation>");
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
    printf("\nENTREI - <sum>");
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

void term(){
    printf("\nENTREI - <term>");
    factor();
    while (1){
        if (lookahead== OPERADOR_MULTIPLICACAO){
            consome(OPERADOR_MULTIPLICACAO);
            factor();
        }else if (lookahead == OPERADOR_SUBTRACAO){
            consome(OPERADOR_SUBTRACAO);
            factor();
        }else{
            break;
        }
    }
}

void factor() {
    printf("\nENTREI - <factor>");
    if(lookahead == INTCONST){
        consome(INTCONST);
    }else if(lookahead == CHARCONST){
        consome(CHARCONST);
    } else if(lookahead == IDENTIFICADOR){
        consome(IDENTIFICADOR);
    }else if(lookahead == ABRE_PAR){
        consome(ABRE_PAR);
        expr();
        consome(FECHA_PAR);
    }
}

int main(){
    Aluno();

    printf("\nIniciando leitura do arquivo...\n");
    entrada = ler_arquivo("Arquivos de Teste/Arquivo_E.txt");

    info_atomo = obter_atomo();

    while(info_atomo.atomo != ERRO || info_atomo.atomo != EOS){
        info_atomo = obter_atomo();
        if(info_atomo.atomo == ERRO){
            printf("\nERRO");
            return 0;
        }
    
        if(info_atomo.atomo == EOS){
            printf("FIM DO ANALISADOR LEXICO");
            return 0;
        }
    }

    // lookahead = info_atomo.atomo;

    // program();
    // consome(EOS);

    return 0;
}