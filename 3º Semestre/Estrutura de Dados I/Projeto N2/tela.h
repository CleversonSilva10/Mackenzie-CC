#include <iostream>
using namespace std;

void id_alunos() {
  std :: cout << "\nProf. IVAN CARLOS ALCANTARA DE OLIVEIRA - TURMA: 03N\n\nAtividade de Aplicação - APl2\n";
  std :: cout << "\nIntegrantes da dupla\n--------------------------------------------------\n";
  std :: cout << "Nome: Cleverson Pereira da Silva - TIA: 32198531\n";
  std :: cout << "Nome: Gustavo Teixeira dos Santos - TIA: 32197020";
  std :: cout << "\n--------------------------------------------------\n";
};

void menu(){
  std :: cout << "---------------- MENU ---------------------" << endl;
  std :: cout << "1. Ler dados" << endl;
  std :: cout << "2. Exibir dados" << endl;
  std :: cout << "3. Salvar dados" << endl;
  std :: cout << "4. Inserir livro" << endl;
  std :: cout << "5. Remover livro" << endl;
  std :: cout << "6. Análise de dados A" << endl;
  std :: cout << "7. Análise de dados B" << endl;
  std :: cout << "8. Análise de dados C" << endl;
  std :: cout << "9. Encerrar" << endl;
  std :: cout << "---------------------------------------------" << endl << endl;
};

void opcao_escolhida(int opcao){
  if (opcao == 1){
    cout << " --------------------------- " << endl;
    cout << "         1. Ler dados        ";
    cout << endl << " --------------------------- " << endl << endl;    
  }
  if (opcao == 2){
      cout << " --------------------------- " << endl;
      cout << "         2. Exibir dados     ";
      cout << endl << " --------------------------- " << endl << endl;
  }
  if (opcao == 3){
      cout << " --------------------------- " << endl;
      cout << "         3. Salvar dados     ";
      cout << endl << " --------------------------- " << endl << endl;
  }
  if (opcao == 4){
      cout << " --------------------------- " << endl;
      cout << "         4. Inserir livro    ";
      cout << endl << " --------------------------- " << endl << endl;
  }
  if (opcao == 5){
      cout << " --------------------------- " << endl;
      cout << "         5. Remover livro    ";
      cout << endl << " --------------------------- " << endl << endl;
  }
  if (opcao == 6){
      cout << " --------------------------- " << endl;
      cout << "         6. Análise de dados A    ";
      cout << endl << " --------------------------- " << endl << endl;
  }
  if (opcao == 7){
      cout << " --------------------------- " << endl;
      cout << "         7. Análise de dados B";
      cout << endl << " --------------------------- " << endl << endl;
  }
  if (opcao == 8){
      cout << " --------------------------- " << endl;
      cout << "         8. Análise de dados C    ";
      cout << endl << " --------------------------- " << endl << endl; 
  }
  if (opcao == 9){
      cout << " --------------------------- " << endl;
      cout << "         9. Programa Finalizado!    ";
      cout << endl << " --------------------------- " << endl << endl; 
  }      
};