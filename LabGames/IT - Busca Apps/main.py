from download_img import download_img
from info_usuario import *
from search_playstore import busca_PlayStore
from salvar_dados import salvar_csv

def id_aluno():
    print('\n---------------------------------------------------')
    print("Nome: Cleverson Pereira da Silva - TIA: 32198531")
    print('---------------------------------------------------\n')

id_aluno()

while(1):
    menu()
    opcao = int(input("\nQual opção desejada: "))
    if opcao == 1:
        Num_Pesquisa, Base_de_dados, Link_Google, Nome_do_app, Ultima_atualização, Preço, Downloads, palavra_chave, Idade, Finalidade, Nota_app = busca_PlayStore()
        menu1()
        opcao1 = int(input("\nQual opção desejada: "))
        if opcao1 == 1:
            salvar_csv(Num_Pesquisa, Base_de_dados, Link_Google, Nome_do_app, Ultima_atualização, Preço, Downloads, palavra_chave, Idade, Finalidade, Nota_app)
            info1()
    elif opcao == 9:
        encerrar()
        break