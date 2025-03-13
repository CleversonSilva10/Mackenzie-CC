#include <iostream>
#include <fstream>
#include "Tnode.hpp"
#include "tela.h"
using namespace std;

int leitura_doc(){
    ifstream arquivo;
    arquivo.open("bibliografia.csv");
    if (arquivo.fail()) {
        return 0;
    }else{
        while (arquivo.peek() != EOF){
            string linha;
            getline(arquivo, linha, ';');
            // cout << linha << endl;
        }
        return 1;
    }
}

int main(){
    int opcao;
    id_alunos(); // Apresentação dos integrantes!
    if (leitura_doc() == 1){
        while (opcao != 9){
            menu(); // Informa as opções possiveis;
            cout << "Digite a opcao desejada: "; cin >> opcao; cout << endl;
            switch(opcao){
                case 1:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 2:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 3:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 4:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 5:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 6:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 7:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 8:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;
                case 9:   
                opcao_escolhida(opcao); // Informar qual opção foi escolhida
                break;                                                                                                                                
            }
        }
    }
}