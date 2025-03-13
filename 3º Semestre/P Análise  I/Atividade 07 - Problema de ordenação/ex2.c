#include <stdio.h>
#include <string.h>

struct alunos{
    char turma[10];
    int matricula;
    float nota;
};

int main(){
    int tamanho, i, j, opcao, aux_m, terminar, aux_n; char sel_turma[10];
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
    printf("Prof: CHARLES BOULHOSA RODAMILANS - Turma: 03N\n");

    FILE *arq; 
    arq = fopen("notas_alunos.txt", "r");

    printf("\nDigite o número de alunos desejados: "); scanf("%d", &tamanho);
    struct alunos a[tamanho];

    for (i = 0; i<tamanho; i++){
        fscanf(arq, "%s %d %f", a[i].turma, &a[i].matricula, &a[i].nota);
    }

    printf("\n------ MENU -------");
    printf("\n1 - Ordenado por turma e matricula/Solicite uma turma e mostre somente os alunos da turma em ordem de matricula.\n2 - Ordenado por nota (uma classificação geral de todas as turmas)\n");
    printf("3 - Solicite uma turma e mostre somente os alunos da turma em ordem decrescente nota.\n\n");
    printf("Qual opção desejada?: "); scanf("%d", &opcao);

    if (opcao == 1){
        printf("Digite a turma desejada: "); scanf("%s", sel_turma);
        for (i = 0; i<tamanho; i++){
            for (j = i; j<tamanho; j++){
                if (strcmp(a[i].turma, sel_turma) == 0){
                    if (a[i].matricula > a[j].matricula){
                        aux_m = a[i].matricula;
                        a[i].matricula = a[j].matricula;
                        a[j].matricula = aux_m;
                    }
                }
            }
        }
        for (i = 0; i<tamanho; i++){
            if (strcmp(a[i].turma, sel_turma) == 0){
                printf("\nTurma : %s - Matricula: %d - Notas: %.2lf", a[i].turma, a[i].matricula, a[i].nota);
            }
        }
    }
    if (opcao == 2){
        for (i = 0; i<tamanho; i++){
            for (j = i; j<tamanho; j++){
                if (strcmp(a[i].turma, "A") == 0){
                    if (a[i].nota>a[j].nota){
                        aux_m = a[i].matricula;
                        a[i].matricula = a[j].matricula;
                        a[j].matricula = aux_m;

                        aux_n = a[i].nota;
                        a[i].nota = a[j].nota;
                        a[j].nota = aux_n;
                    }
                }
                if (strcmp(a[i].turma, "B") == 0){
                    if (a[i].nota>a[j].nota){
                        aux_m = a[i].matricula;
                        a[i].matricula = a[j].matricula;
                        a[j].matricula = aux_m;

                        aux_n = a[i].nota;
                        a[i].nota = a[j].nota;
                        a[j].nota = aux_n;
                    }
                }                                                                                                                     
                if (strcmp(a[i].turma, "C") == 0){
                    if (a[i].nota>a[j].nota){
                        aux_m = a[i].matricula;
                        a[i].matricula = a[j].matricula;
                        a[j].matricula = aux_m;

                        aux_n = a[i].nota;
                        a[i].nota = a[j].nota;
                        a[j].nota = aux_n;
                    }
                }
                if (strcmp(a[i].turma, "D") == 0){
                    if (a[i].nota>a[j].nota)
                        aux_m = a[i].matricula;
                        a[i].matricula = a[j].matricula;
                        a[j].matricula = aux_m;

                        aux_n = a[i].nota;
                        a[i].nota = a[j].nota;
                        a[j].nota = aux_n;
                    }
                }
            }
        for (i=0; i<tamanho; i++){
            printf("\nTurma : %s - Matricula: %d - Notas: %.2lf", a[i].turma, a[i].matricula, a[i].nota);
        }
    }
    if (opcao == 3){
        printf("Digite a turma desejada: "); scanf("%s", sel_turma);
        for (i = 0; i<tamanho; i++){
            for (j = i; j<tamanho; j++){
                if (strcmp(a[i].turma, sel_turma) == 0){
                    if (a[i].matricula < a[j].matricula){
                        aux_m = a[i].matricula;
                        a[i].matricula = a[j].matricula;
                        a[j].matricula = aux_m;
                    }
                }
            }
        }
        for (i = 0; i<tamanho; i++){
            if (strcmp(a[i].turma, sel_turma) == 0){
                printf("\nTurma : %s - Matricula: %d - Notas: %.2lf", a[i].turma, a[i].matricula, a[i].nota);
            }
        }
    }
}