#include "Class_No.cpp"

class ArvoreBST{
  private:
    No *raiz;

  public:
    ArvoreBST(){
      raiz = NULL;
    }
    void setRaiz(No* root){
      raiz = root;
    }
    void inserir(int chave)
    {
      if(raiz == NULL) 
        raiz = new No(chave); 
      else
        inserirAux(raiz, chave);
    }

    void inserirAux(No *no, int chave){
        if(chave < no->getChave()){
          if(no->getEsq() == NULL){
              No *novo_no = new No(chave);
              no->setEsq(novo_no);
            }
            else{
                inserirAux(no->getEsq(), chave);
            }
        }
        // se for maior, ent�o insere na sub-�rvore � direita
        else if(chave > no->getChave()){
            // verifica se n�o tem filho a direita: achou local de inser��o
            if(no->getDir() == NULL){
              No *novo_no = new No(chave);
              no->setDir(novo_no); // add o novo_no � direita do n� atual
            }
            else{
              // sen�o, continua percorrendo recursivamente para direita
              inserirAux(no->getDir(), chave);
            }
        }
        // se a chave for igual a alguma presente na �rvore, n�o vamos inserir
        // n�o pode existir 2 chaves iguais na nossa BST
    }


    No* getRaiz(){
      return raiz;
    }

    void emOrdem(No* no){
      if(no != NULL){
        emOrdem(no->getEsq());
        cout << no->getChave() << " ";
        emOrdem(no->getDir());
      }
    }

    void preOrdem(No* no){
        if(no != NULL){
          cout << no->getChave() << " ";
          preOrdem(no->getEsq());
          preOrdem(no->getDir());
        }
    }

    void posOrdem(No* no){
      if(no != NULL){
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getChave() << " ";
      }
    }

    //versao recursiva
    int altura(No* atual){
      if(atual == NULL)
        return -1;
      else{
            if(atual->getEsq() == NULL && atual->getDir() == NULL)
              return 0;
            else{
                if (altura(atual->getEsq()) > altura(atual->getDir()))
                    return ( 1 + altura(atual->getEsq()) );
                else
                    return ( 1 + altura(atual->getDir()) );
            }
        }
    }
    
    int min(){
        No *atual = raiz;
        No *anterior = NULL;
        while (atual != NULL){
          anterior = atual;
          atual = atual->getEsq();
        }
        return anterior->getChave();
    }

    No* findMin(No* t){
        if(t == NULL)
          return NULL;
        else if(t->getEsq() == NULL)
            return t;
        else
            return findMin(t->getEsq());
    }
    
    void print(){
  		print(raiz, 0);
    }

	void print(No *no, int space){
  		if (no != NULL){	
    		print(no->getDir(), space + 5);
    		for (int k = 0; k < space; ++k){
				cout << " ";
            }
    		cout << no->getChave() << "\n";
    		print(no->getEsq(), space + 5);
  		}
    }

    bool pesquisa(No *raiz, int key){
        if (raiz == nullptr){
            return false;
        }
        if (raiz->getChave() == key){
            return true;
        }
        if (key < raiz->getChave()){
            return pesquisa(raiz->getEsq(), key);
        }else{
            return pesquisa(raiz->getDir(), key);
        }
    }
    
    int countNodes(No *raiz) {
    if (raiz == nullptr) {
        return 0;
    }
        return 1 + countNodes(raiz->getEsq()) + countNodes(raiz->getDir());
    }

    int Folhas(No* raiz){
        if (raiz == nullptr){
            return 0;
        }
        if (raiz->getEsq() == nullptr && raiz->getDir() == nullptr){
            return 1;
        }
        return Folhas(raiz->getEsq()) + Folhas(raiz->getDir());
    }

    int FindMax(No* raiz){
        if (raiz == nullptr){
            return 0;
        }
        while(raiz->getDir() != nullptr){
            raiz = raiz->getDir();
        }
        return raiz->getChave();
    }

    No* maior_dos_menores(No *raiz){
      No* ponteiro_anda = raiz->getEsq();
      if (ponteiro_anda->getDir() == nullptr){
        return ponteiro_anda;
      }
      while(ponteiro_anda->getDir()->getDir() != nullptr){
        ponteiro_anda = ponteiro_anda->getDir();
      }
      return ponteiro_anda;
    }

    No* menor_dos_maiores(No *raiz){
      No* ponteiro_anda = raiz->getDir();
      if (ponteiro_anda->getEsq() != nullptr){
        while(ponteiro_anda->getEsq()->getEsq() != nullptr){
          ponteiro_anda = ponteiro_anda->getEsq();
        }
      }
      return ponteiro_anda;
    }    

    No* excluir(No *raiz, No *no_pai, int key){
      No *aux = no_pai; // INFORMAR A SUB_ARVORE
      if (raiz != nullptr){
        if (raiz->getChave() == key && raiz->getEsq() != nullptr && raiz->getDir() != nullptr){
          No *aux_folha;
          if (key < this->getRaiz()->getChave()){
            No *aux_pai = maior_dos_menores(raiz);
            if (aux_pai->getDir() == nullptr){
              aux_folha = aux_pai;
              // aux_folha->setEsq(nullptr);
            }else{
              aux_folha = aux_pai->getDir();
              aux_pai->setDir(nullptr);
              aux_folha->setEsq(raiz->getEsq());
            }
          aux_folha->setDir(raiz->getDir());
          aux_pai = nullptr;
          }else{
            No *aux_pai = menor_dos_maiores(raiz);
            if (aux_pai->getEsq() == nullptr){
              aux_folha = aux_pai;
              //aux_folha->setDir(nullptr);
            }else{
              aux_folha = aux_pai->getEsq();
              aux_pai->setEsq(nullptr);
              aux_folha->setDir(raiz->getDir());
            }
            aux_folha->setEsq(raiz->getEsq());
            aux_pai = nullptr;
          }
          if (no_pai->getChave() > aux_folha->getChave()){
            no_pai->setEsq(aux_folha);
          }else{
            no_pai->setDir(aux_folha);
          }
          delete(raiz);
          raiz = nullptr;
          aux_folha = nullptr;
          no_pai = nullptr;
          return nullptr;
        }
        // POSSUI UNICO FILHO A ESQUERDA     
        if (raiz->getChave() == key && raiz->getEsq() != nullptr){
          aux->setEsq(raiz->getEsq());
          delete(raiz);
          return nullptr;
        }
        // POSSUI UNICO FILHO A DIREITA
        if (raiz->getChave() == key && raiz->getDir() != nullptr){
          aux->setDir(raiz->getDir());
          delete(raiz);
          return nullptr;
        }

        // SE CHAVE FOR UM NÓ FOLHA
        if (raiz->getChave() == key && raiz->getEsq() == nullptr && raiz->getDir() == nullptr){          
          delete(raiz);
          return nullptr;
        }else if(key < raiz->getChave()){
          return excluir(raiz->getEsq(), raiz, key);
        }else{
          cout << aux->getChave();
          return excluir(raiz->getDir(), raiz, key);
        }
      }else{
        cout << "Arvore Vazia";
        return nullptr;
      }
    }
  };