#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Aluno(){
    printf("\n---------------------------------------------------------\n");
    printf("Nome: Cleverson Pereira da Silva - RA: 10391119\n");
    printf("Nome: Felipe Nakandakari dos Santos - RA: 1039516\n");
    printf("Prof: Fabio Luba");
    printf("\n---------------------------------------------------------\n");
}

char *entrada;
int contalinhas = 1;

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
    int quantidade_caracteres;
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
    atomo.linha = contalinhas; // Guarda a linha atual
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
    atomo.linha = contalinhas; // Guarda a linha atual

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

    entrada++;
    return atomo;
}


TInfoAtomo reconhecer_operador_comparacao() {
    TInfoAtomo atomo;
    atomo.linha = contalinhas; // Armazena o número da linha atual

    // Verifica os operadores de comparação e atribuição
    if (*entrada == '=' && *(entrada + 1) == '=') {
        // Igualdade (==)
        atomo.atomo = OPERADOR_COMPARACAO_IGUAL;
        entrada += 2;
    } else if (*entrada == '<' && *(entrada + 1) == '=') {
        // Menor ou igual (<=)
        atomo.atomo = OPERADOR_COMPARACAO_MENOR_IGUAL;
        entrada += 2;
    } else if (*entrada == '>' && *(entrada + 1) == '=') {
        // Maior ou igual (>=)
        atomo.atomo = OPERADOR_COMPARACAO_MAIOR_IGUAL;
        entrada += 2;
    } else if (*entrada == '!' && *(entrada + 1) == '=') {
        // Diferente (!=)
        atomo.atomo = OPERADOR_COMPARACAO_DIFERENTE;
        entrada += 2;
    } else if (*entrada == '<') {
        // Menor (<)
        atomo.atomo = OPERADOR_COMPARACAO_MENOR;
        entrada++;
    } else if (*entrada == '>') {
        // Maior (>)
        atomo.atomo = OPERADOR_COMPARACAO_MAIOR;
        entrada++;
    } else if (*entrada == '=' && *(entrada + 1) != '=') {
        // Atribuição (=)
        atomo.atomo = ATRIBUICAO;
        entrada++;
    } else if (*entrada == '|' && *(entrada + 1) == '|') {
        // OU lógico (||)
        atomo.atomo = OPERADOR_COMPARACAO_OR;
        entrada += 2;
    } else if (*entrada == '&' && *(entrada + 1) == '&') {
        // E lógico (&&)
        atomo.atomo = OPERADOR_COMPARACAO_AND;
        entrada += 2;
    } else {
        // Se não for nenhum dos casos acima, é erro
        atomo.atomo = ERRO;
        entrada++;
    }
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
    
    entrada++; // consome a aspa de fechamento
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

    entrada += 2; // pula o '0x'

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
    printf("\n%03d# Obter_Atomo: %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if (info_atomo.atomo == IDENTIFICADOR ||
        info_atomo.atomo == CHAR || info_atomo.atomo == INT ||
        info_atomo.atomo == VOID || info_atomo.atomo == MAIN ||
        info_atomo.atomo == WHILE || info_atomo.atomo == IF ||
        info_atomo.atomo == ELSE || info_atomo.atomo == READINT ||
        info_atomo.atomo == WRITEINT) {
        printf(" | %s", info_atomo.atributo_ID);
    }
    else if (info_atomo.atomo == CHARCONST) {
        printf(" | '%c' (ASCII: %c)", info_atomo.Num_Tabela_ASCII, info_atomo.Num_Tabela_ASCII);
    }
    else if (info_atomo.atomo == INTCONST) {
        printf(" | %d", (int)info_atomo.atributo_numero);
    }
}

void consome(TAtomo atomo) {
    Apresentar_Atomo(info_atomo);
    printf("\n%03d# Consome: %s", info_atomo.linha, strAtomo[atomo]);
    if (lookahead == atomo) {
        info_atomo = obter_atomo();
        lookahead = info_atomo.atomo;
    } else {
        printf("\nErro sintatico: esperado [%s] encontrado [%s]\n", strAtomo[atomo], strAtomo[lookahead]);
        exit(1);
    }
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
        consome(IDENTIFICADOR);
        if (lookahead == ATRIBUICAO) {
            consome(ATRIBUICAO);
            expr();
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
        consome(IDENTIFICADOR);
        consome(FECHA_PAR);
        consome(PONTO_VIRGULA);
    } else if (lookahead == WRITEINT) {
        consome(WRITEINT);
        consome(ABRE_PAR);
        expr();
        consome(FECHA_PAR);
        consome(PONTO_VIRGULA);
    }
}


void assig_stmt() {
    if (lookahead == IDENTIFICADOR) {
        consome(IDENTIFICADOR);
        consome(ATRIBUICAO);
        expr();
        consome(PONTO_VIRGULA);
    }
}


void cond_stmt() {
    consome(IF); consome(ABRE_PAR); expr(); consome(FECHA_PAR);
    stmt();
    if (lookahead == ELSE) {
        consome(ELSE);
        stmt();
    }
}

void while_stmt() {
    consome(WHILE); consome(ABRE_PAR); expr(); consome(FECHA_PAR);
    stmt();
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
        relation();
        sum();
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
    if (lookahead == INTCONST || lookahead == CHARCONST || lookahead == IDENTIFICADOR)
        consome(lookahead);
    else if (lookahead == ABRE_PAR) {
        consome(ABRE_PAR);
        expr();
        consome(FECHA_PAR);
    }
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

    info_atomo = obter_atomo();    
    lookahead = info_atomo.atomo; 

    program();

    if (lookahead == EOS) {
        printf("\n\nPrograma sintaticamente correto - %d linhas analisadas\n\n", info_atomo.linha);
    } else {
        printf("Erro sintático: entrada não consumida completamente.\n\n");
    }

    free(entrada);
    return 0;
}