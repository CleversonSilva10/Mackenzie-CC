#include <stdio.h>
#include <pthread.h>


double conta = 0;

void Alunos_Grupo(){
    printf("\n----------------------- GRUPO --------------------------");
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
    printf("\nNome: Felipe Nakandakari dos Santos - TIA: 42104701");
    printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020\n");
    printf("-------------------------------------------------------");
}


void *primos(void *arg){
    int valor = *((int *)arg);

    if (valor <= 1){
        printf("\nNumero %d: False", valor);
        return NULL;
    }

    for (int i = 2; i * i <= valor; i++){
        if ((valor % i) == 0){
            printf("\nNumero %d: False", valor); 
            return NULL;
        }
    }

    printf("\nNumero %d: True", valor); 
    return NULL;
}

int main() {
    Alunos_Grupo();
    int k = 30; // Define o valor de k
    pthread_t thread_primos;

    for (int j = 2; j <= k; j++) {
        pthread_create(&thread_primos, NULL, primos, &j);
        pthread_join(thread_primos, NULL);
    }

    return 0;
}