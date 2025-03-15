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

    if(*entrada == '/'){
        info_atomo = reconhece_comentario();
        return info_atomo;
    }

    while(*entrada == ' ' || *entrada == '\n' || *entrada == '\r' || *entrada == '\t'){
        if(*entrada == '\n'){
            // Contagem de Linhas
            contalinhas++;
        }else if(*entrada == '\0'){
            info_atomo.atomo = EOS;
        }
    }

    // RECONHECER TOKEN

    if (isdigit(*entrada)){
        info_atomo = reconhecer_num();
    }
    else if (islower(*entrada)){
        info_atomo = reconhecer_id();
    }

    info_atomo.linha = contalinhas;
    
    return info_atomo;
}

TInfoAtomo reconhece_comentario(){
    TInfoAtomo info_comentario;
    info_comentario.atomo= ERRO;
    
    if(*entrada == '/' && *(entrada+1) == '/'){
        entrada += 2; //APONTAR PARA INICIO DO POSSIVEL COMENTARIO
        while (*entrada != '\n'){
            entrada++; //DENTRO DO COMENTARIO
        }
            info_comentario.atomo = COMENTARIO;
    }

    if(*entrada == '/' && *(entrada+1) == '*'){
        entrada += 2; //APONTAR PARA INICIO DO POSSIVEL COMENTARIO
        while (*entrada != '*' && *entrada != '/'){
            entrada++; //DENTRO DO COMENTARIO
        }
            info_comentario.atomo = COMENTARIO;
    }
    
    return info_comentario;
}
    
TInfoAtomo reconhecer_id(){
    TInfoAtomo info_id;
    info_id.atomo = ERRO;
    int cont_caracteres_id = 0;

    if(isupper(*entrada) || islower(*entrada) || *entrada == '_'){
        entrada++;
        cont_caracteres_id++;
    }

    while ((*entrada == '\0')){
        if(isupper(*entrada) || islower(*entrada) || *entrada == '_' || isdigit(*entrada)){
            entrada++;
            cont_caracteres_id++;
            if(cont_caracteres_id > 15){
                info_id.atomo = ERRO;
                return info_id;
            }
        }
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
    strncpy(str_num, inicio_num, entrada - inicio_num);
    str_num[entrada - inicio_num] = '\0';  
    info_num.atributo_numero = atof(str_num);
    return info_num;
}