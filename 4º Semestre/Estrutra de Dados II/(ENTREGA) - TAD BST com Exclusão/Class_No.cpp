#include <iostream>
using namespace std;
  
class No{
  private:
    No *esq, *dir;
    int chave;
    
  public:
    No(int chave){
      this->chave = chave;
      esq = NULL;
      dir = NULL;
    }
  //getters and setters
  int getChave(){
    return chave;
  }
  No* getEsq(){
      return esq;
  }
  No* getDir(){
    return dir;
  }
  void setChave(int k){
    chave = k;
  }
  void setEsq(No *no){
    esq = no;
  }
  void setDir(No *no){
    dir = no;
  }

};