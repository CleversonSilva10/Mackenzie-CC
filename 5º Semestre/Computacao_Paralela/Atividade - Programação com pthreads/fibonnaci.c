#include <stdio.h>

/*
Calcular o Fibonacci de forma paralela é difícil devido às dependências entre os cálculos, o que resultaria em baixo desempenho, 
mesmo com mutexes. É mais eficiente fazer isso de forma sequencial.
*/

void Alunos_Grupo(){
    printf("\n----------------------- GRUPO --------------------------");
    printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
    printf("\nNome: Felipe Nakandakari dos Santos - TIA: 42104701");
    printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020\n");
    printf("-------------------------------------------------------");
}

int main(){
    Alunos_Grupo();
    printf("\n\nResposta: \n\nCalcular o Fibonacci de forma paralela é difícil devido às dependências entre os cálculos, \no que resultaria em baixo desempenho, mesmo com mutexes. É mais eficiente fazer isso de forma sequencial.\n\n");
    return 0;
}