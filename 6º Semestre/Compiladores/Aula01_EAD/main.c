#include <stdio.h>

void Aluno(){
    printf("\n-------------------------------------------------\n");
    printf("Nome: Cleverson Pereria da Silva - RA: 10391119\n");
    printf("Disciplina: Compiladores / Prof Fabio Luba");
    printf("\n-------------------------------------------------\n\n");
}

int Impar_A_Par_B(char *entrada);

int main(void){
    Aluno();
    char *entrada = "ababbaaba";
    printf("Resposta: %d \n", Impar_A_Par_B(entrada));
}

int Impar_A_Par_B(char *entrada){

PA_PB:
    if(*entrada == 'a'){
        entrada++; // Antes de desviar, consumir entrada! (Avança ponteiro)
        goto IA_PB;
    }
    if(*entrada == 'b'){
        entrada++; // Antes de desviar, consumir entrada! (Avança ponteiro)
        goto PA_IB;
    }
    return 0; // Estado Não-Final

IA_PB:
    if(*entrada == 'a'){
        entrada++; // Antes de desviar, consumir entrada! (Avança ponteiro)
        goto PA_PB;
    }
    if(*entrada == 'b'){
        entrada++; // Antes de desviar, consumir entrada! (Avança ponteiro)
        goto IA_IB;
    } 
    return *entrada == '\0'; // Estado Final

PA_IB:
    if(*entrada == 'a'){
        entrada++; // Antes de desviar, consumir entrada! (Avança ponteiro)
        goto IA_IB;
    }
    if(*entrada == 'b'){
        entrada++; // Antes de desviar, consumir entrada! (Avança ponteiro)
        goto PA_PB;
    }
    return 0; // Estado Não-Final

IA_IB:
    if(*entrada == 'a'){
        entrada++;
        goto PA_IB;
    }
    if(*entrada == 'b'){
        entrada++;
        goto IA_IB;
    }
    return 0; // Estado Não-Final
}