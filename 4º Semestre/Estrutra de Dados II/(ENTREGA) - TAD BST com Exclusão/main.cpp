#include "arvore_binaria.cpp"

// ESTRUTURA DE DADOS II - TURMA 04N11
// Nome: Cleverson Pereira da Silva - TIA: 32198531
// Nome: Gustavo Teixeira dos Santos - TIA: 32197020

void integrantes() {
  cout << "\nIntegrantes\n--------------------------------------------------\n";
  cout << "Nome: Cleverson Pereira da Silva - TIA: 32198531\n";
  cout << "Nome: Gustavo Teixeira dos Santos - TIA: 32197020\n";
  cout << "--------------------------------------------------\n";
}

int main(){
    ArvoreBST arv;
    integrantes();
    int opcao, x; 
    do
    {
        cout << "\n";
        cout << "\n***************************************************************************";        
        cout << "\n                         MENU - Arvore BST\n";
        cout << "***************************************************************************";
        cout << "\n";

        cout << "\n****************************PROFESSOR***********************************************";
        cout << "\n ----1: Inserir";
        cout << "\n ----2: Pesquisar";
        cout << "\n ----3: Imprimir em ordem";        
        cout << "\n ----4: Informacoes";
        cout << "\n ----5: Imprimir 2D\n";
        cout << "\n****************************FEITO PELO INTEGRANTES***********************************************";                
        cout << "\n ----6: Excluir_Remover";
        cout << "\n ----7: Pesquisar o elemento";
        cout << "\n ----8: Contar o número de nós existentes";
        cout << "\n ----9: Contar Folhas"; 
        cout << "\n ----10: O maior elemento da arvore"; 
        cout << "\n***************************************************************************";        
        cout << "\n ----11: Sair do programa\n";           
        cout << "\nOp: ";
        cin >> opcao;
        cout << "\n\n";
        
        switch(opcao){
        case 1:{
          cout << "\n Informe o valor (int) -> ";
          cin >> x;
          arv.inserir(x);
          break;
        }
        case 2:{
          cout << "\n Informe o valor da chave (int) -> ";
          cin >> x;
          break;
        }
        case 3:{
          cout << "Percorrendo em ordem...\n";
          arv.emOrdem(arv.getRaiz());
          break;
        }
        case 4:{
        	cout << "Mostrar: altura, qde de nos, qde de folhas etc\n";
          break;
        }
        case 5:{
        	arv.print();
          break;
        }
        case 6:{
          cout << "\n Informe o valor (int) -> ";
          cin >> x;
          arv.excluir(arv.getRaiz(), arv.getRaiz(), x);
          break;
        }        
        case 7:{
          cout << "Pesquisa na árvore\n";
          cout << "Qual número deseja pesquisar?: "; cin >> x;
          if (arv.pesquisa(arv.getRaiz() , x) == true){
            cout << "O elemento foi encontrado!";
          }else{
            cout << "O elemento não foi encontrado!";
          }
          break;
        }
        case 8:{
        	cout << "Contagem de nos: " << arv.countNodes(arv.getRaiz());
          break;
        }
        case 9:{
        	cout << "Contagem de folhas: " << arv.Folhas(arv.getRaiz());
          break;
        }
        case 10:{
            cout << "Maior elemento da arvore: " << arv.FindMax(arv.getRaiz());
            break;
        }
        case 11:{
            arv.maior_dos_menores(arv.getRaiz());
            break;
        }                                     
        default:
            if (opcao != 12)
                cout << "\n Opcao invalida! \n\n\n";
        } // fim switch
    }
    while(opcao != 12);

    return 0;
}