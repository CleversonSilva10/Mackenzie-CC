#include "header.h"

char *entrada;
int contalinhas = 1;

void Aluno(){
    printf("\n----------------------------------------\n");
    printf("Nome: Cleverson Pereira da Silva - RA: 10391119\n");
    printf("-------------------------------------------\n");
}

char *lerArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Descobrir o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    // Alocar memória para armazenar o conteúdo
    char *conteudo = (char *)malloc((tamanho + 1) * sizeof(char));
    if (!conteudo) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return NULL;
    }

    // Ler o arquivo para a string
    fread(conteudo, 1, tamanho, arquivo);
    conteudo[tamanho] = '\0'; // Garantir terminação da string

    fclose(arquivo);
    return conteudo;
}

TInfoAtomo obter_atomo() {
    TInfoAtomo info_atomo;
    info_atomo.atomo = ERRO;

    info_atomo = CaracteresDemilitadores();

    if (*entrada == '/') {
        info_atomo = reconhece_comentario();
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

    Apresentar_Atomo(info_chaves, "MENSAGEM NAO NECESSARIA");
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
        printf("\n%03d# %s | %f", info_atomo.linha, strAtomo[info_atomo.atomo], info_atomo.atributo_numero);

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
}