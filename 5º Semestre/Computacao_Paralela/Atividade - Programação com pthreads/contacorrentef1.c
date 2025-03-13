#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double conta = 0;

void Alunos_Grupo(){
    printf("\n----------------------- GRUPO --------------------------");
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
    printf("\nNome: Felipe Nakandakari dos Santos - TIA: 42104701");
    printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020\n");
    printf("-------------------------------------------------------");
}

void *deposito(){
    for (int i = 0; i < 99999; i++){
        conta += 30;
    }
    return NULL;
}

void *saque(){
    for (int i = 0; i < 99999; i++){
        conta -= 10;
    }
    return NULL;
}

int main(){
    Alunos_Grupo();

    // Criando as threads
    pthread_t thread_deposito, thread_saque;
    
    // Inicializando as threads
    pthread_create(&thread_deposito, NULL, deposito, NULL);
    pthread_create(&thread_saque, NULL, saque, NULL);

    // Sincronização das threads 
    pthread_join(thread_deposito, NULL);
    pthread_join(thread_saque, NULL);

    printf("\n\nSaldo Final: %.2f\n", conta);
    
    return 0;
}
