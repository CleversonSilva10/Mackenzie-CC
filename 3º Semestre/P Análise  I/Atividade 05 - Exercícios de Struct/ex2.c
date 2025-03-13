#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
    char nome[20];
    float peso;
    float altura;
    int cpf;
    char sexo[15];
};

void menu(){
    printf("\n\n-----------------MENU-------------------\n");
    printf("1 - Cadastrar as pessoas\n");
    printf("2 - Encontrar uma pessoa\n");
    printf("3 - Finalizar o programa!\n");
    printf("----------------------------------------\n");
}

int main(){
    char nome[20], sexo[15]; float peso, altura, imc; int cpf, tam_cad, opcao, terminar, i, input_cpf; 

  printf("\nRealizado 04/09/2022");
  printf("\n------------------------\n");
  printf("Nome Cleverson Pereira da Silva - TIA 32198531");
  printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 2022");
  printf("\nExercicio 2");
  printf("\n------------------------\n");

    printf("\nDigite o número de pesssoas que deseja cadastrar: "); scanf("%d", &tam_cad);
    struct pessoa p[tam_cad];
    
    while (terminar != 3){
        menu(); printf("\nQual opção desejada?: "); scanf("%d", &opcao);
        if (opcao == 1){
            for (i = 0; i<tam_cad; i++){
                printf("\n%d - Pessoa", i+1);
                printf("\n----------------------------------------");
                printf("\nDigite o nome: "); scanf("%s", &p[i].nome);
                printf("Digite o peso: "); scanf("%f", &p[i].peso);
                printf("Digite a altura: "); scanf("%f", &p[i].altura);
                printf("Digite o CPF: "); scanf("%d", &p[i].cpf);
                printf("Digite o sexo: "); scanf("%s", &p[i].sexo);
                printf("----------------------------------------\n");
            }
        }
        if (opcao == 2){
            printf("\nDigite o CPF desejado: "); scanf("%d", &input_cpf);
            for (i = 0; i<tam_cad; i++){
                if (p[i].cpf == input_cpf){
                    printf("\n | CPF ENCONTRADO! | \n");
                    printf("\n----------------------------------------");
                    printf("\nNome: %s \n", p[i].nome);
                    printf("Peso: %.2f \n", p[i].peso);
                    printf("Altura: %.2f \n", p[i].altura);
                    printf("CPF: %d \n", p[i].cpf);
                    printf("Sexo: %s \n", p[i].sexo);
                    imc = p[i].peso/(p[i].altura*p[i].altura);
                    printf("IMC: %.2f \n", imc);
                    printf("----------------------------------------\n");
                }else{
                    printf("\n | CPF NÃO ENCONTRADO! | \n");
                }
            }        
        }
        if (opcao == 3){
            printf("\nPrograma Finalizado!\n"); terminar = 3;    
        }        
    }
}