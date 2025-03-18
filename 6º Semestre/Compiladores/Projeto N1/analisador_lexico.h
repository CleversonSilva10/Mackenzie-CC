#include "header.h"



void Aluno(){
    printf("\n----------------------------------------\n");
    printf("Nome: Cleverson Pereira da Silva - RA: 10391119\n");
    printf("-------------------------------------------\n");
}

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

    info_atomo = CaracteresDemilitadores();

    if(*entrada == '\''){
        info_atomo = reconhece_Tabela_ASCII();
        return info_atomo;
    }

    if (*entrada == '/') {
        info_atomo = reconhece_comentario();
        // *entrada == '/' DIVISAO
        return info_atomo;
    }

    if (*entrada == '0' && *(entrada+1) == 'x') {
        info_atomo = reconhece_Hexadecimal();
        return info_atomo;
    }

    if (*entrada == '='){ // Operação de ATRIBUIÇÃO
        info_atomo = reconhece_Operando();
        return info_atomo;
    }

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

    if ((*entrada == '+') || (*entrada == '-') || (*entrada == '*') || (*entrada == '/' && *(entrada+1) != '/')){
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

        if (*entrada == '\0') {
            info_demilitadores.atomo = EOS;
            return info_demilitadores;
        }
        
        entrada++;
    }

    info_demilitadores.linha = contalinhas;
    //Chegando aqui estou com um caracter que precisa ser analisado
    return info_demilitadores; // Já saiu dos caracteres delimitadores
}

TInfoAtomo reconhece_Tabela_ASCII() {
    TInfoAtomo info_tabela_ascii;
    info_tabela_ascii.atomo = ERRO;  

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
        info_tabela_ascii.Num_Tabela_ASCII = atoi(temp);  

        if (*entrada == '\'') {  
            entrada++; 
            info_tabela_ascii.atomo = TABELA_ASCII;
            info_tabela_ascii.linha = contalinhas;
            Apresentar_Atomo(info_tabela_ascii, "NAO PRECISA DE MENSAGEM");
        }
    }

    return info_tabela_ascii;
}

// hexa → A|B|C|D|E|F
// intconst → 0x(hexa|digito)+

TInfoAtomo reconhece_Hexadecimal() {
    TInfoAtomo info_hexadecimal;
    info_hexadecimal.atomo = ERRO;
    info_hexadecimal.atributo_numero = 0;

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

        info_hexadecimal.atomo = HEXADECIMAL;
        info_hexadecimal.atributo_numero = resultado;
        info_hexadecimal.linha = contalinhas++;
        
        Apresentar_Atomo(info_hexadecimal, "NAO PRECISA DE MENSAGEM");
        return info_hexadecimal;
    }
    
    Apresentar_Atomo(info_hexadecimal, "NAO PRECISA DE MENSAGEM");
    return info_hexadecimal;
}



TInfoAtomo reconhece_Operando(){
    TInfoAtomo info_operador;
    info_operador.atomo = ERRO;

    if (*entrada == '=') {
        entrada++;
        info_operador.atomo = ATRIBUICAO;
    } 
    else if (*entrada == '|') {
        if (*(entrada + 1) == '|'){
            entrada += 2;
            info_operador.atomo = OPERADOR_COMPARACAO_OR;
        }
    } 
    else if (*entrada == '&') {
        if (*(entrada + 1) == '&') {
            entrada += 2;
            info_operador.atomo = OPERADOR_COMPARACAO_AND;
        }
    } 
    else if (*entrada == '<') {
        if (*(entrada + 1) == '=') {
            entrada += 2;
            info_operador.atomo = OPERADOR_COMPARACAO_MENOR_IGUAL;
        } else {
            entrada++;
            info_operador.atomo = OPERADOR_COMPARACAO_MENOR;
        }
    } 
    else if (*entrada == '>') {
        if (*(entrada + 1) == '=') {
            entrada += 2;
            info_operador.atomo = OPERADOR_COMPARACAO_MAIOR_IGUAL;
        } else {
            entrada++;
            info_operador.atomo = OPERADOR_COMPARACAO_MAIOR;
        }
    } 
    else if (*entrada == '!') {
        if (*(entrada + 1) == '=') {
            entrada += 2;
            info_operador.atomo = OPERADOR_COMPARACAO_DIFERENTE;
        }
    }else if (*entrada == '+') {
        entrada++;
        info_operador.atomo = OPERADOR_SOMA;
    } 
    else if (*entrada == '-') {
        entrada++;
        info_operador.atomo = OPERADOR_SUBTRACAO;
    } 
    else if (*entrada == '*') {
        entrada++;
        info_operador.atomo = OPERADOR_MULTIPLICACAO;
    } 
    else if (*entrada == '/') {
        entrada++;
        info_operador.atomo = OPERADOR_DIVISAO;
    }

    Apresentar_Atomo(info_operador, "MENSAGEM NAO NECESSARIA");
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

    return info_chaves;
}

TInfoAtomo reconhece_ponto_virgula(){
    TInfoAtomo info_pontoVirgula;
    info_pontoVirgula.atomo = ERRO;

    if (*entrada == ';'){
        entrada++;
        info_pontoVirgula.atomo = PONTO_VIRGULA;
    }else if (*entrada == ','){
        entrada++;
        info_pontoVirgula.atomo = VIRGULA;
    }

    Apresentar_Atomo(info_pontoVirgula, "MENSAGEM NAO NECESSARIA");
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
            info_comentario.atomo = COMENTARIO;
            Apresentar_Atomo(info_comentario, "MENSAGEM NAO NECESSARIA");
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
            info_comentario.atomo = COMENTARIO;
            Apresentar_Atomo(info_comentario, "MENSAGEM NAO NECESSARIA");
            return info_comentario;
        }
    }

    Apresentar_Atomo(info_comentario, "COMENTARIO INVALIDO");
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

    if(info_atomo.atomo == OPERADOR_SUBTRACAO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_MULTIPLICACAO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == OPERADOR_DIVISAO)
    printf("\n%03d# %s", info_atomo.linha, strAtomo[info_atomo.atomo]);

    if(info_atomo.atomo == HEXADECIMAL)
    printf("\n%03d# %s | %.2f", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_numero);

    if(info_atomo.atomo == TABELA_ASCII)
    printf("\n%03d# %s | %c", info_atomo.linha, strAtomo[info_atomo.atomo], (char)info_atomo.Num_Tabela_ASCII);
}