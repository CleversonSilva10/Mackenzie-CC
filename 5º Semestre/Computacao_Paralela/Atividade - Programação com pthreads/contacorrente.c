#include <stdio.h>


double conta = 0;

void Alunos_Grupo(){
    printf("\n----------------------- GRUPO --------------------------");
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
    printf("\nNome: Felipe Nakandakari dos Santos - TIA: 42104701");
    printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020\n");
    printf("-------------------------------------------------------");
}

int main(){
    Alunos_Grupo();

    // Deposito na conta
    for (int i = 0; i<1000; i++){
        conta += 1;
    }
    
    printf("\n\nConta com os depositos: %.2f", conta);

    // Saque da Conta
    for (int i = 0; i>1000; i++){
        conta += 0.5;
    }

    printf("\nConta com os saques realizados: %.2f\n", conta);
    
    return 0;
}