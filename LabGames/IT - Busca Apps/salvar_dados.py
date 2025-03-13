import csv

def salvar_csv(Num_Pesquisa, Base_de_dados, Link_Google, Nome_do_app, Ultima_atualização, Preço, Downloads, palavra_chave, Idade, Finalidade, Nota_app):
    with open('Busca_Completa.csv', 'a', newline='', encoding='utf-8') as csvfile:
        campos = ['Loja', 'Link - Google', 'Nome', 'Ultima atualização', 'Preço', 'Downloads', 'Palavra Chave', 'Classificação Indicativa', 'Finalidade - Sobre Aplicativo', 'Avaliação do Aplicativo']
        write = csv.DictWriter(csvfile, fieldnames=campos)
        write.writeheader()

        for i in range(0, Num_Pesquisa):
            write.writerow({'Loja': f'{Base_de_dados[i]}', 'Link - Google': f'{Link_Google[i]}', 'Nome': f'{Nome_do_app[i]}', 'Ultima atualização': f'{Ultima_atualização[i]}', 'Preço': f'{Preço[i]}', 'Downloads': f'{Downloads[i]}', 'Palavra Chave': f'{palavra_chave[i]}', 'Classificação Indicativa': f'{Idade[i]}','Finalidade - Sobre Aplicativo': f'{Finalidade[i]}', 'Avaliação do Aplicativo': f'{Nota_app[i]}'})
    
    csvfile.close()
