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

TInfoAtomo obter_atomo(){
    TInfoAtomo info_atomo;
    info_atomo.atomo = ERRO;

    if (*entrada == '/'){
        info_atomo = reconhece_comentario();
        return info_atomo;
    }

    if (isdigit(*entrada)){
        info_atomo = reconhecer_num();
    }
    else if (isalpha(*entrada) || *entrada == '_'){
        info_atomo = reconhecer_id();
    }
    
    while(*entrada == ' ' || *entrada == '\n' || *entrada == '\r' || *entrada == '\t'){
        entrada++;
        if(*entrada == '\0'){
            info_atomo.atomo = EOS;
            return info_atomo;
        }
        if(*entrada == '\n'){
            contalinhas++;
        }
    }

    info_atomo.linha = contalinhas;
    return info_atomo;
}

TInfoAtomo reconhece_comentario() {
    TInfoAtomo info_comentario;
    info_comentario.atomo = ERRO;

    if((*entrada == '/' && *(entrada+1) == '/') || (*entrada == '/' && *(entrada+1) == '*')){
        entrada += 2; // Dentro do Comentario
        while ((*entrada != '/' && *(entrada+1) != '/') || (*entrada != '/' && *(entrada+1) != '/')){
            if(*entrada == '\n'){
                contalinhas++;
            }else if (*entrada == '\0'){
                return info_comentario;
            }
            entrada++;
        }
    }

    entrada += 2;
    info_comentario.linha = contalinhas;
    info_comentario.atomo = COMENTARIO;
    return info_comentario;
}


TInfoAtomo reconhecer_id(){
    TInfoAtomo info_id;
    info_id.atomo = ERRO;
    int i = 0;  // Índice para armazenar letras em atributo_ID

    while (*entrada != '\0' && *entrada != ' ' && *entrada != '\n') {
        if (!isalpha(*entrada) && !isdigit(*entrada) && *entrada != '_') {
            return info_id;
    }
        if (i < 16) {  // Certifique-se de não ultrapassar o tamanho do array
            info_id.atributo_ID[i] = *entrada;  // Armazena o caractere em atributo_ID
            i++;
        }
        entrada++;
    }

    info_id.atributo_ID[i] = '\0';  // Finaliza a string com o caractere nulo
    info_id.atomo = IDENTIFICADOR;
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
    return info_num;
}
