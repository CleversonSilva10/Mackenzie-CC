#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define TAM_MEMORIA sizeof(int)

// Cleverson Pereira da Silva - TIA: 32198531

void aluno(){
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Disciplina: Computação Paralela - [05N11]");
}

int main() {
    int id_memoria;
    int *valor_compartilhado;
    key_t chave = 10;

    id_memoria = shmget(chave, TAM_MEMORIA, IPC_CREAT | 0666);
    if (id_memoria == -1) {
        perror("shmget");
        exit(1);
    }

    valor_compartilhado = (int *)shmat(id_memoria, NULL, 0);
    if (*valor_compartilhado == -1) {
        perror("shmat");
        exit(1);
    }

    *valor_compartilhado = 1;
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid != 0) {
        printf("PAI - Valor inicial da variável compartilhada: %d\n", *valor_compartilhado);
        wait(NULL);
        
        valor_compartilhado = (int *)shmat(id_memoria, NULL, 0);
        *valor_compartilhado *= 4;

        printf("PAI - Valor após multiplicação: %d\n", *valor_compartilhado);
        shmdt(valor_compartilhado);
        shmctl(id_memoria, IPC_RMID, NULL); // Liberar a memória compartilhada

        exit(0);
    } else {
        printf("FILHO - Valor inicial da variável compartilhada: %d\n", *valor_compartilhado);
        *valor_compartilhado += 2;
        printf("Filho - Valor Modificado: %d\n", *valor_compartilhado);
        shmdt(valor_compartilhado);
        exit(0);
    }
    return 0;
}