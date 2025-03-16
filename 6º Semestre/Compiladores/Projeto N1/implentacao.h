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

    // Ignorar espaços em branco e novas linhas antes de reconhecer qualquer token
    while (*entrada == ' ' || *entrada == '\n' || *entrada == '\r' || *entrada == '\t') {
        if (*entrada == '\n') {
            contalinhas++;
        }
        
        entrada++;
        if (*entrada == '\0') {
            info_atomo.atomo = EOS;
            return info_atomo;
        }
    }

    if (*entrada == '/') {
        info_atomo = reconhece_comentario();
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

    info_atomo.linha = contalinhas;
    return info_atomo;
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
            }

            entrada++; // Para sair da linha de comentário
            info_comentario.linha = contalinhas;
            info_comentario.atomo = COMENTARIO;
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

    while (*entrada != '\0' && *entrada != ' ' && *entrada != '\n') {
        if (!isalpha(*entrada) && !isdigit(*entrada) && *entrada != '_') {
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
        //TESTE - IDENTIFICAR ERRO NO IDENTIFICADOR
        //printf("\n%03d# %s | ATOMO: %s | Quantidade: %d", info_id.linha, strAtomo[info_id.atomo], info_id.atributo_ID, info_id.quantidade_caracteres);
    }

    if (strcmp(info_id.atributo_ID, "char") == 0) {
        info_id.atomo = CHAR;
    } else if (strcmp(info_id.atributo_ID, "else") == 0) {
        info_id.atomo = ELSE;
    } else if (strcmp(info_id.atributo_ID, "if") == 0) {
        info_id.atomo = IF;
    } else if (strcmp(info_id.atributo_ID, "int") == 0) {
        info_id.atomo = INT;
    } else if (strcmp(info_id.atributo_ID, "main") == 0) {
        info_id.atomo = MAIN;
    } else if (strcmp(info_id.atributo_ID, "readint") == 0) {
        info_id.atomo = READINT;
    } else if (strcmp(info_id.atributo_ID, "void") == 0) {
        info_id.atomo = VOID;
    } else if (strcmp(info_id.atributo_ID, "while") == 0) {
        info_id.atomo = WHILE;
    } else if (strcmp(info_id.atributo_ID, "writeint") == 0) {
        info_id.atomo = WRITEINT;
    }else{
        info_id.atomo = IDENTIFICADOR;
    }

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
    return info_num;
}
