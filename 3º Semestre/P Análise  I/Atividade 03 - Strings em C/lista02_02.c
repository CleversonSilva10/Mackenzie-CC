#include <stdio.h>
#include <string.h>


int main(){
    char string1[20], string2[20], string3[20];
    printf("\nRealizado 20/08/2022");
    printf("\n------------------------\n");
    printf("Nome Cleverson Pereira da Silva - TIA 32198531");
    printf("\nProf. Charles Boulhosa Rodamilans - [Turma 03N] - 20222");
    printf("\n------------------------\n");

    printf("\nDigite a primeira palavra: "); scanf("%s", &string1);
    printf("Digite a segunda palavra: "); scanf("%s", &string2);
    printf("Digite a terceira palavra: "); scanf("%s", &string3);

    if(strcmp(string1,string2) >= 0){

      if(strcmp(string2,string3) >= 0){
        // PRINT 3,2,1
        printf("%s %s %s",string3,string2,string1);
      }else if(strcmp(string1,string3) >= 0){
        //print 2,3,1
        printf("%s %s %s",string2,string3,string1);
      }else{
        // print 2,1,3
        printf("%s %s %s",string2,string1,string3);
      }
      
    }else{

      if(strcmp(string2,string3) >= 0){

        if(strcmp(string1,string3) >= 0){
          //PRINT 3,1,2
          printf("%s %s %s",string3,string1,string2);
        }else{
          //PRINT 1,3,2
          printf("%s %s %s",string1,string3,string2);
          }
        
      }else{
        // PRINT 1,2,3
        printf("%s %s %s",string1,string2,string3);
      }
      
    }
  }