#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  _ACEITA_ 1
#define  _REJEITA_ 0
#define _ACEITA_FLOAT 2

void Alunos_Grupo(){
    printf("---------------- GRUPO ----------------------------\n");
    printf("Nome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Nome: Gustavo Teixeira dos Santos - TIA: 32197020\n");
    printf("Nome: João Victor Silva Mota - TIA: 32308124\n");
    printf("Nome: Victor Junqueira Colombaro - TIA: 42123712\n");
    printf("-----------------------------------------------------");
};

int Scanner(const char * string, int tamanho_string){
    int posicao = 0;
    int virgula = 0;

    // PONTO INCIAL
    Q0:
        if (string[posicao] == 0){
            posicao += 1;
            printf("\nQ0 -> Q7\n");
            goto Q7;

        }else if (string[posicao] == '+' || string[posicao] == '-'){
            posicao += 1;
            printf("\nQ0 -> Q2\n");
            goto Q2;

        }else if (string[posicao] == '.' || string[posicao] == ','){
            posicao += 1;
            printf("\nQ0 -> Q4\n");
            goto Q4;

        }else if (string[posicao] >= 1 && string[posicao] <= 9){
            posicao += 1;
            printf("\nQ0 -> Q6\n");
            goto Q6;
        }else{
            return _REJEITA_;
        }
    
    Q1:
        if (posicao == tamanho_string){
            return _REJEITA_;
        }

        if (string[posicao] == '.' || string[posicao] == ',' || string[posicao] == '+' || string[posicao] == '-'){
            posicao += 1;
            printf("Q1 -> Q4\n");
            goto Q4;

        }else if (string[posicao] >= 0 && string[posicao] <= 9){
            posicao += 1;
            printf("Q1 -> Q8\n");
            goto Q8;
        }else{
            return _REJEITA_;
        }
    
    Q2:
        if (posicao == tamanho_string){
            return _REJEITA_;
        }

        if (string[posicao] == '.' || string[posicao] == ',' || string[posicao] == '+' || string[posicao] == '-'){
            posicao += 1;
            printf("Q2 -> Q4\n");
            goto Q4;

        }else if(string[posicao] == 0){
            posicao += 1;
            printf("Q2 -> Q5\n");
            goto Q5;

        }else if (string[posicao] >= 1 || string[posicao] <= 9){
            posicao += 1;
            printf("Q2 -> Q6\n");
            goto Q6; 
        }else{
            return _REJEITA_;
        }
    
    Q3:
        if (posicao == tamanho_string){
            return _REJEITA_;
        }

        if(string[posicao] == 0){
            posicao += 1;
            printf("Q3 -> Q3\n");
            goto Q3;
        }else if (string[posicao] == '.' || string[posicao] == ',' || string[posicao] == '+' || string[posicao] == '-'){
            posicao += 1;
            printf("Q3 -> Q4\n");
            goto Q4;
        }else if (string[posicao] >= 1 && string[posicao] <= 9){
            posicao += 1;
            printf("Q3 -> Q8\n");
            goto Q8;
        }else{
            return _REJEITA_;
        }
    
    Q4:
        if (posicao == tamanho_string){
            return _REJEITA_;

        }else if (string[posicao] == '.' || string[posicao] == ',' || string[posicao] == '+' || string[posicao] == '-' || (string[posicao] >= 0 && string[posicao] <= 9)){
            posicao += 1;
            printf("Q4 -> Q4\n");
            goto Q4;
        }else{
            return _REJEITA_;
        }
    
    Q5:
        if (posicao == tamanho_string){
            return _REJEITA_;
        }

        if (string[posicao] == '.' || string[posicao] == '+' || string[posicao] == '-' || (string[posicao] >= 1 && string[posicao] <= 9)){
            posicao += 1;
            printf("Q5 -> Q4\n");
            goto Q4;

        }else if (string[posicao] == ','){
            posicao += 1;
            virgula = 1;
            printf("Q5 -> Q3\n");
            goto Q3;
        }else{
            return _REJEITA_;
        }
    
    Q6:
        // --------- ESTADO FINAL --------------
        if (posicao == tamanho_string){
            return _ACEITA_;
        // -------------------------------------
        
        }else if(string[posicao] == '.' || string[posicao] == '+' || string[posicao] == '-'){
            posicao += 1;
            printf("Q6 -> Q4\n");
            goto Q4;

        }else if (string[posicao] >= 1 && string[posicao] <= 9){
            posicao += 1;
            printf("Q6 -> Q6\n");
            goto Q6;
    
        }else if (string[posicao] == ','){
            posicao += 1;
            virgula = 1;
            printf("Q6 -> Q1\n");
            goto Q1;
        }else{
            return _REJEITA_;
        }
    
    Q7:
        // --------- ESTADO FINAL --------------
        if (posicao == tamanho_string){
            return _ACEITA_;
        // -------------------------------------

        }else if (string[posicao] == '.' || string[posicao] == '+' || string[posicao] == '-' || (string[posicao] >= 1 && string[posicao] <= 9)){
            posicao += 1;
            printf("Q7 -> Q4\n");
            goto Q4;
            
        }else if (string[posicao] == ','){
            posicao += 1;
            virgula = 1;
            printf("Q7 -> Q3\n");
            goto Q3;
        }else{
            return _REJEITA_;
        }
    
    Q8:
        // --------- ESTADO FINAL --------------
        if (posicao == tamanho_string){
            if (virgula == 1){
                return _ACEITA_FLOAT;
            }else{
                return _ACEITA_;
            }
        // -------------------------------------

        }else if (string[posicao] >= 0 && string[posicao] <= 9){
            posicao += 1;
            printf("Q8 -> Q8\n");
            goto Q8;
        
        }else if (string[posicao] == '.' || string[posicao] == ',' || string[posicao] == '+' || string[posicao] == '-'){
            posicao += 1;
            printf("Q8 -> Q4\n");
            goto Q4;
        }else{
            return _REJEITA_;
        }
}

int main(){
    Alunos_Grupo();
    char Entrada_String[100]; int resultado;
    strcpy(Entrada_String, "0J1111"); // DIGITE A PALAVRA DESEJADA 

    size_t tamanho_string = strlen(Entrada_String);
    printf("\n\nPalavra inserida: %s", Entrada_String);

    for (int i = 0; i <= tamanho_string - 1; i++) {
        if (isdigit(Entrada_String[i])) {
            Entrada_String[i] = Entrada_String[i] - '0';
        }   
    }

    printf("\nTamanho da string: %ld\n", tamanho_string);

    resultado = Scanner(Entrada_String, tamanho_string);

    if (resultado == 1){
        printf("\n<INTEIRO>");
        printf("\n\n---------------------");
        printf("\nPalavra Aceita\n");
        printf("---------------------\n\n");
    }else if (resultado == 2){
        printf("\n<PONTO FLUTUANTE>");
        printf("\n\n---------------------");
        printf("\nPalavra Aceita\n");
        printf("---------------------\n\n");
    }else{
        printf("\n\n---------------------");
        printf("\nPalavra Rejeitada: <ERRO>\n");
        printf("---------------------\n\n");
    }

    return 0;
}