#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Nome: Cleverson Pereira da Silva - RA: 10391119
// Nome: Felipe Nakandakari dos Santos - RA: 1039516

void Aluno(){
    printf("---------------------------------------------------------\n");
    printf("Nome: Cleverson Pereira da Silva - RA: 10391119\n");
    printf("Nome: Felipe Nakandakari dos Santos - RA: 1039516\n");
    printf("---------------------------------------------------------\n");
}


char *entrada;
int contalinhas = 1;
int QtdadeLexemas = 0;
int rotuloAtual = 0;


char *strAtomo[] = {
    "ERRO", "IDENTIFICADOR", "NUMERO", "COMENTARIO", "EOS",
    "CHAR", "ELSE", "IF", "INT", "MAIN", "READINT", "VOID", "WHILE", "WRITEINT",
    "ABRE_PAR", "FECHA_PAR", "ABRE_CHAVE", "FECHA_CHAVE", "VIRGULA", "PONTO_VIRGULA",
    "ATRIBUICAO", "OPERADOR_COMPARACAO_IGUAL", "OPERADOR_COMPARACAO_OR",
    "OPERADOR_COMPARACAO_AND", "OPERADOR_COMPARACAO_MENOR_IGUAL", "OPERADOR_COMPARACAO_MENOR",
    "OPERADOR_COMPARACAO_MAIOR_IGUAL", "OPERADOR_COMPARACAO_MAIOR", "OPERADOR_COMPARACAO_DIFERENTE",
    "OPERADOR_SOMA", "OPERADOR_SUBTRACAO", "OPERADOR_MULTIPLICACAO", "OPERADOR_DIVISAO",
    "INTCONST", "CHARCONST"
};

const char *palavrasReservadas[] = {
    "char", "else", "if", "int", "main", "readint", "void", "while", "writeint"
};

typedef enum {
    ERRO, IDENTIFICADOR, NUMERO, COMENTARIO, EOS,
    CHAR, ELSE, IF, INT, MAIN, READINT, VOID, WHILE, WRITEINT,
    ABRE_PAR, FECHA_PAR, ABRE_CHAVE, FECHA_CHAVE, VIRGULA, PONTO_VIRGULA,
    ATRIBUICAO, OPERADOR_COMPARACAO_IGUAL, OPERADOR_COMPARACAO_OR,
    OPERADOR_COMPARACAO_AND, OPERADOR_COMPARACAO_MENOR_IGUAL, OPERADOR_COMPARACAO_MENOR,
    OPERADOR_COMPARACAO_MAIOR_IGUAL, OPERADOR_COMPARACAO_MAIOR, OPERADOR_COMPARACAO_DIFERENTE,
    OPERADOR_SOMA, OPERADOR_SUBTRACAO, OPERADOR_MULTIPLICACAO, OPERADOR_DIVISAO,
    INTCONST, CHARCONST
} TAtomo;

typedef struct {
    TAtomo atomo;
    int linha;
    float atributo_numero;
    char Num_Tabela_ASCII;
    char atributo_ID[16];
} TInfoAtomo;

TInfoAtomo info_atomo;
TAtomo lookahead;

TInfoAtomo reconhecer_identificador();
TInfoAtomo reconhecer_simbolo();
TInfoAtomo reconhecer_operador_comparacao();
TInfoAtomo reconhecer_operador_logico();
TInfoAtomo reconhecer_operador_aritmetico();
TInfoAtomo reconhecer_charconst();
TInfoAtomo reconhecer_intconst();

void consome(TAtomo atomo);
void program();
void compound_stmt();
void var_decl();
void type_specifier();
void var_decl_list();
void variable_id();
void type_decl_type();
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

void adicionar_simbolo(char *nome);
int buscar_endereco(char *nome);

typedef struct _TNo{
    char ID[16];
    int endereco;
    struct _TNo *prox;
}TNo;
   
TNo *tabela = NULL;
int enderecoAtual = 0;

void ignorar_delimitadores() {
    while (*entrada == ' ' || *entrada == '\n' || *entrada == '\r' || *entrada == '\t') {
        if (*entrada == '\n') {
            contalinhas++;
        }
        entrada++;
    }
}

void ignorar_comentarios() {
    while ((*entrada == '/' && *(entrada + 1) == '/') || (*entrada == '/' && *(entrada + 1) == '*')) {
        if (*entrada == '/' && *(entrada + 1) == '/') {
            entrada += 2;
            while (*entrada != '\n' && *entrada != '\0') {
                entrada++;
            }
            if (*entrada == '\n') {
                contalinhas++;
                entrada++;
            }
        } else if (*entrada == '/' && *(entrada + 1) == '*') {
            entrada += 2;
            while (!(*entrada == '*' && *(entrada + 1) == '/') && *entrada != '\0') {
                if (*entrada == '\n') {
                    contalinhas++;
                }
                entrada++;
            }
            if (*entrada == '*' && *(entrada + 1) == '/') {
                entrada += 2;
            }
        }
        ignorar_delimitadores();
    }
}

TAtomo verificar_palavra_reservada(const char *identificador) {
    for (int i = 0; i < 9; i++) {
        if (strcmp(identificador, palavrasReservadas[i]) == 0) {
            return CHAR + i;
        }
    }
    QtdadeLexemas++;
    return IDENTIFICADOR;
}

TInfoAtomo obter_atomo() {
    TInfoAtomo atomo;
    ignorar_delimitadores();
    ignorar_comentarios();
    ignorar_delimitadores();

    if (*entrada == '\0') {
        atomo.atomo = EOS; // Fim do arquivo
        atomo.linha = contalinhas;
        return atomo;
    }

    if (isalpha(*entrada) || *entrada == '_') {
        return reconhecer_identificador();
    }

    if (*entrada == '(' || *entrada == ')' || *entrada == '{' ||
        *entrada == '}' || *entrada == ';' || *entrada == ',') {
        return reconhecer_simbolo();
    }

    if (*entrada == '=' || *entrada == '<' || *entrada == '>' ||
        *entrada == '!' || *entrada == '|' || *entrada == '&') {
        return reconhecer_operador_comparacao();
    }

    if (*entrada == '+' || *entrada == '-' || *entrada == '*' || *entrada == '/') {
        return reconhecer_operador_aritmetico();
    }

    if (*entrada == '\'' && isdigit(*(entrada + 1))) {
        return reconhecer_charconst();
    }

    if (*entrada == '0' && *(entrada + 1) == 'x') {
        return reconhecer_intconst();
    }

    atomo.atomo = ERRO;
    atomo.linha = contalinhas;
    entrada++;
    return atomo;
}



TInfoAtomo reconhecer_identificador() {
    TInfoAtomo atomo;
    atomo.linha = contalinhas;
    int i = 0;

    while ((isalpha(*entrada) || isdigit(*entrada) || *entrada == '_') && i < 15) {
        atomo.atributo_ID[i] = *entrada; 
        i++;
        entrada++;
    }

    atomo.atributo_ID[i] = '\0';
    atomo.atomo = verificar_palavra_reservada(atomo.atributo_ID);
    return atomo;
}

TInfoAtomo reconhecer_simbolo() {
    TInfoAtomo atomo;
    atomo.linha = contalinhas;

    if (*entrada == '(') {
        atomo.atomo = ABRE_PAR;
    } else if (*entrada == ')') {
        atomo.atomo = FECHA_PAR;
    } else if (*entrada == '{') {
        atomo.atomo = ABRE_CHAVE;
    } else if (*entrada == '}') {
        atomo.atomo = FECHA_CHAVE;
    } else if (*entrada == ';') {
        atomo.atomo = PONTO_VIRGULA;
    } else if (*entrada == ',') {
        atomo.atomo = VIRGULA;
    } else {
        atomo.atomo = ERRO;
    }

    QtdadeLexemas++;
    entrada++;
    return atomo;
}


TInfoAtomo reconhecer_operador_comparacao() {
    TInfoAtomo atomo;
    atomo.linha = contalinhas; 

    if (*entrada == '=' && *(entrada + 1) == '=') {
        atomo.atomo = OPERADOR_COMPARACAO_IGUAL;
        entrada += 2;
    } else if (*entrada == '<' && *(entrada + 1) == '=') {
        atomo.atomo = OPERADOR_COMPARACAO_MENOR_IGUAL;
        entrada += 2;
    } else if (*entrada == '>' && *(entrada + 1) == '=') {
        atomo.atomo = OPERADOR_COMPARACAO_MAIOR_IGUAL;
        entrada += 2;
    } else if (*entrada == '!' && *(entrada + 1) == '=') {
        atomo.atomo = OPERADOR_COMPARACAO_DIFERENTE;
        entrada += 2;
    } else if (*entrada == '<') {
        atomo.atomo = OPERADOR_COMPARACAO_MENOR;
        entrada++;
    } else if (*entrada == '>') {
        atomo.atomo = OPERADOR_COMPARACAO_MAIOR;
        entrada++;
    } else if (*entrada == '=' && *(entrada + 1) != '=') {
        atomo.atomo = ATRIBUICAO;
        entrada++;
    } else if (*entrada == '|' && *(entrada + 1) == '|') {
        atomo.atomo = OPERADOR_COMPARACAO_OR;
        entrada += 2;
    } else if (*entrada == '&' && *(entrada + 1) == '&') {
        atomo.atomo = OPERADOR_COMPARACAO_AND;
        entrada += 2;
    } else {
        atomo.atomo = ERRO;
        entrada++;
    }
    QtdadeLexemas++;
    return atomo;
}


TInfoAtomo reconhecer_operador_aritmetico() {
    TInfoAtomo atomo;
    atomo.linha = contalinhas;

    if (*entrada == '+') {
        atomo.atomo = OPERADOR_SOMA;
        entrada++;
    } else if (*entrada == '-') {
        atomo.atomo = OPERADOR_SUBTRACAO;
        entrada++;
    } else if (*entrada == '*') {
        atomo.atomo = OPERADOR_MULTIPLICACAO;
        entrada++;
    } else if (*entrada == '/') {
        if (*(entrada + 1) != '/' && *(entrada + 1) != '*') {
            atomo.atomo = OPERADOR_DIVISAO;
            entrada++;
        } else {
            atomo.atomo = ERRO;
        }
    } else {
        atomo.atomo = ERRO;
        entrada++;
    }
    return atomo;
}


TInfoAtomo reconhecer_charconst() {
    TInfoAtomo atomo;
    atomo.linha = contalinhas;
    atomo.atomo = CHARCONST;
    entrada++; 

    char buffer[4] = {0};
    int i = 0;

    while (isdigit(*entrada) && i < 3) {
        buffer[i++] = *entrada++;
    }

    if (*entrada != '\'') {
        atomo.atomo = ERRO;
    }
    
    entrada++; 

    int valor = atoi(buffer);
    if (valor < 0 || valor > 127) {
        atomo.atomo = ERRO;
    }

    atomo.Num_Tabela_ASCII = valor;
    return atomo;
}


TInfoAtomo reconhecer_intconst() {
    TInfoAtomo atomo;
    atomo.linha = contalinhas;
    atomo.atomo = INTCONST;

    entrada += 2;

    char buffer[10];
    int i = 0;

    while (isxdigit(*entrada) && i < 9) {
        buffer[i] = *entrada;
        entrada++;
        i++;
    }

    buffer[i] = '\0'; 

    if (isalpha(*entrada) && !isxdigit(*entrada)) {
        atomo.atomo = ERRO;
    }

    atomo.atributo_numero = (float)strtol(buffer, NULL, 16);
    return atomo;
}



void Apresentar_Atomo(TInfoAtomo info_atomo) {
    // printf("\n%03d# Obter_Atomo: %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    // if (info_atomo.atomo == IDENTIFICADOR ||
    //     info_atomo.atomo == CHAR || info_atomo.atomo == INT ||
    //     info_atomo.atomo == VOID || info_atomo.atomo == MAIN ||
    //     info_atomo.atomo == WHILE || info_atomo.atomo == IF ||
    //     info_atomo.atomo == ELSE || info_atomo.atomo == READINT ||
    //     info_atomo.atomo == WRITEINT) {
    //     printf(" | %s", info_atomo.atributo_ID);
    // }
    // else if (info_atomo.atomo == CHARCONST) {
    //     printf(" | '%c' (ASCII: %c)", info_atomo.Num_Tabela_ASCII, info_atomo.Num_Tabela_ASCII);
    // }
    // else if (info_atomo.atomo == INTCONST) {
    //     printf(" | %d", (int)info_atomo.atributo_numero);
    // }
}

void consome(TAtomo atomo) {
    Apresentar_Atomo(info_atomo);
    //printf("\n%03d# Consome: %s", info_atomo.linha, strAtomo[atomo]);
    if (lookahead == atomo) {
        info_atomo = obter_atomo();
        lookahead = info_atomo.atomo;
        if (info_atomo.atomo == ERRO) {
            printf("\n%03d# ERRO: Atomo nao reconhecido pelo analisador lexico.\n", info_atomo.linha);
            exit(1);
        }
    } else {
        printf("\nErro sintatico: esperado [%s] encontrado [%s]\n", strAtomo[atomo], strAtomo[lookahead]);
        exit(1);
    }
}

int proximo_rotulo() {
    return rotuloAtual++;
}



void program() {
    consome(VOID);
    consome(MAIN);
    consome(ABRE_PAR);
    consome(VOID);
    consome(FECHA_PAR);
    compound_stmt();
}

void compound_stmt() {
    consome(ABRE_CHAVE);

    while (lookahead == INT || lookahead == CHAR ||
           lookahead == ABRE_CHAVE || lookahead == IDENTIFICADOR || lookahead == IF ||
           lookahead == WHILE || lookahead == READINT || lookahead == WRITEINT) {

        if (lookahead == INT || lookahead == CHAR)
            var_decl();
        else
            stmt();
    }

    consome(FECHA_CHAVE);
}

void var_decl() {
    type_specifier();
    var_decl_list();
    consome(PONTO_VIRGULA);
}

void type_specifier() {
    if (lookahead == INT || lookahead == CHAR)
        consome(lookahead);
}

void var_decl_list() {
    variable_id();
    while (lookahead == VIRGULA) {
        consome(VIRGULA);
        variable_id();
    }
}


void variable_id() {
    if (lookahead == IDENTIFICADOR) {
        char nomeVar[16];
        strcpy(nomeVar, info_atomo.atributo_ID);
        consome(IDENTIFICADOR);

        if (lookahead == ATRIBUICAO) {
            adicionar_simbolo(nomeVar);
            consome(ATRIBUICAO);
            expr();
            int endereco = buscar_endereco(nomeVar);
            printf("|\t ARMZ %d\t\t|\n", endereco);
        } else {
            adicionar_simbolo(nomeVar);
        }
    }
}


void stmt() {
    if (lookahead == ABRE_CHAVE) {
        compound_stmt();
    } else if (lookahead == IDENTIFICADOR) {
        assig_stmt();
    } else if (lookahead == IF) {
        cond_stmt();
    } else if (lookahead == WHILE) {
        while_stmt();
    } else if (lookahead == READINT) {
        consome(READINT);
        consome(ABRE_PAR);
        char nomeVar[16];
        strcpy(nomeVar, info_atomo.atributo_ID);
        consome(IDENTIFICADOR);
        consome(FECHA_PAR);
        consome(PONTO_VIRGULA);
        printf("| \tLEIT\t\t|\n");
        printf("| \tARMZ %d\t\t|\n", buscar_endereco(nomeVar));
    } else if (lookahead == WRITEINT) {
        consome(WRITEINT);
        consome(ABRE_PAR);
        expr();
        consome(FECHA_PAR);
        consome(PONTO_VIRGULA);
        printf("| \tIMPR\t\t|\n");
    }
}


void assig_stmt() {
    if (lookahead == IDENTIFICADOR) {
        char nomeVar[16];
        strcpy(nomeVar, info_atomo.atributo_ID);
        consome(IDENTIFICADOR);
        consome(ATRIBUICAO);
        expr();
        printf("| \tARMZ %d\t\t|\n", buscar_endereco(nomeVar));
        consome(PONTO_VIRGULA);
    }
}

void cond_stmt() {
    int L1 = proximo_rotulo();
    int L2 = proximo_rotulo();

    consome(IF);
    consome(ABRE_PAR);
    expr();
    consome(FECHA_PAR);

    printf("| \tDSVF L%d\t\t|\n", L1);
    stmt();
    printf("| \tDSVS L%d\t\t|\n", L2);
    printf("| L%d:\tNADA\t\t|\n", L1);

    if (lookahead == ELSE) {
        consome(ELSE);
        stmt();
    }

    printf("| L%d:\tNADA\t\t|\n", L2);
}

void while_stmt() {
    int L1 = proximo_rotulo();
    int L2 = proximo_rotulo();

    printf("| L%d:\tNADA\t\t|\n", L1);
    consome(WHILE); 
    consome(ABRE_PAR); 
    expr(); 
    consome(FECHA_PAR);
    printf("| \tDSVF L%d\t\t|\n", L2); 
    stmt();
    printf("| \tDSVS L%d\t\t|\n", L1);
    printf("| L%d:\tNADA\t\t|\n", L2);
}

void expr() {
    conjunction();
    while (lookahead == OPERADOR_COMPARACAO_OR) {
        consome(OPERADOR_COMPARACAO_OR);
        conjunction();
    }
}

void conjunction() {
    comparison();
    while (lookahead == OPERADOR_COMPARACAO_AND) {
        consome(OPERADOR_COMPARACAO_AND);
        comparison();
    }
}

void comparison() {
    sum(); 
    if (lookahead == OPERADOR_COMPARACAO_MENOR || lookahead == OPERADOR_COMPARACAO_MENOR_IGUAL ||
        lookahead == OPERADOR_COMPARACAO_IGUAL || lookahead == OPERADOR_COMPARACAO_DIFERENTE ||
        lookahead == OPERADOR_COMPARACAO_MAIOR || lookahead == OPERADOR_COMPARACAO_MAIOR_IGUAL) {
        TAtomo operador = lookahead;
        consome(lookahead); 
        sum();

        switch (operador) {
            case OPERADOR_COMPARACAO_IGUAL:        printf("| \tCMIG\t\t|\n"); break;
            case OPERADOR_COMPARACAO_DIFERENTE:    printf("| \tCMDG\t\t|\n"); break;
            case OPERADOR_COMPARACAO_MENOR:        printf("| \tCMME\t\t|\n"); break;
            case OPERADOR_COMPARACAO_MENOR_IGUAL:  printf("| \tCMEG\t\t|\n"); break;
            case OPERADOR_COMPARACAO_MAIOR:        printf("| \tCMMA\t\t|\n"); break;
            case OPERADOR_COMPARACAO_MAIOR_IGUAL:  printf("| \tCMAG\t\t|\n"); break;
            default:
                printf("Erro: operador de comparação inválido.\n");
                exit(1);
        }
    }
}

void relation() {
    consome(lookahead);
}


void sum() {
    term();
    while (lookahead == OPERADOR_SOMA || lookahead == OPERADOR_SUBTRACAO) {
        consome(lookahead);
        term();
    }
}

void term() {
    factor();
    while (lookahead == OPERADOR_MULTIPLICACAO || lookahead == OPERADOR_DIVISAO) {
        consome(lookahead);
        factor();
    }
}

void factor() {
    if (lookahead == INTCONST) {
        printf("| \tCRCT %d\t\t|\n", (int)info_atomo.atributo_numero);
        consome(INTCONST);
    } else if (lookahead == CHARCONST) {
        printf("| \tCRCT %d\t\t|\n", (int)info_atomo.Num_Tabela_ASCII);
        consome(CHARCONST);
    } else if (lookahead == IDENTIFICADOR) {
        printf("| \tCRVL %d\t\t|\n", buscar_endereco(info_atomo.atributo_ID));
        consome(IDENTIFICADOR);
    } else if (lookahead == ABRE_PAR) {
        consome(ABRE_PAR);
        expr();
        consome(FECHA_PAR);
    }
}

void adicionar_simbolo(char *nome) {
    TNo *ptr = tabela;
    while (ptr) {
        if (strcmp(ptr->ID, nome) == 0) {
            printf("\n-----------------------------------------");
            printf("Erro semantico: variavel [%s] ja declarada.\n", nome);
            exit(1);
        }
        ptr = ptr->prox;
    }

    TNo *novo = (TNo *)malloc(sizeof(TNo));
    strcpy(novo->ID, nome);
    novo->endereco = enderecoAtual++;
    novo->prox = tabela;
    tabela = novo;
}

int buscar_endereco(char *nome) {
    TNo *ptr = tabela;
    while (ptr) {
        if (strcmp(ptr->ID, nome) == 0)
            return ptr->endereco;
        ptr = ptr->prox;
    }
    printf("\n-----------------------------------------\n\n");
    printf("Erro na linha: %d\n", info_atomo.linha);
    printf("Erro semantico: variavel [%s] nao declarada.\n", nome);
    exit(1);
}



void Apresentar_TabelaDeSimbolos() {
    TNo *ptr = tabela;
    printf("\n---------------------------------------------------------\n");
    printf("\t | TABELA DE SIMBOLOS |\n");
    printf("---------------------------------------------------------\n");
    while (ptr != NULL) {
        printf("ID: %s | Endereco: %d\n", ptr->ID, ptr->endereco);
        ptr = ptr->prox;
    }
    printf("---------------------------------------------------------\n");
}


void leArquivo(const char *nome_arquivo) {
    FILE *pFile;
    long lSize;
    size_t result;

    // abre o arquivo
    pFile = fopen(nome_arquivo, "rb");
    if (pFile == NULL) {
        printf("\nfalha na abertura do arquivo %s\n", nome_arquivo);
        exit(1);
    }

    // obtem o tamanho do arquivo
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    rewind(pFile);

    // aloca memória para o conteúdo do arquivo + 1 para '\0'
    entrada = (char *)malloc((lSize + 1) * sizeof(char));
    if (entrada == NULL) {
        printf("\nfalha na alocacao de memoria\n");
        fclose(pFile);
        exit(2);
    }

    // lê o arquivo e copia para o buffer
    result = fread(entrada, 1, lSize, pFile);
    if (result != lSize) {
        printf("\nfalha na leitura do arquivo\n");
        fclose(pFile);
        free(entrada);
        exit(3);
    }

    entrada[lSize] = '\0'; // Finaliza string
    fclose(pFile);
}

int main(int nArgs, char *Args[]) {
    if (nArgs < 2) {
        printf("%s: Número de argumentos insuficiente.\n", Args[0]);
        exit(1);
    }
    
    leArquivo(Args[1]);

    Aluno();

    printf("\nNome do arquivo escolhido: %s\n", Args[1]);

    info_atomo = obter_atomo();    
    lookahead = info_atomo.atomo; 

    printf("\n| \tINPP \t\t|\n");
    program();
    printf("| \tPARA \t\t|\n");

    Apresentar_TabelaDeSimbolos();
    

    if (lookahead == EOS) {
        printf("\nQuantidade de linhas lidas: %d\n", info_atomo.linha);
    } else {
        printf("Erro sintático: entrada não consumida completamente.\n\n");
    }

    free(entrada);
    return 0;
}