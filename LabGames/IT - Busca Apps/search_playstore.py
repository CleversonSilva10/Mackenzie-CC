from requests_html import HTMLSession
from bs4 import BeautifulSoup
from modelar_dados import *

def busca_PlayStore():
    s = HTMLSession()
    print('\n--------------------------------------------------------------')
    pesquisa = input('Digite a pesquisa desejada: ')
    pesquisa = pesquisa.replace(' ', '%20')
    #r = s.get('https://play.google.com/store/search?q='+pesquisa+'&c=apps')
    r = s.get('https://play.google.com/store/search?q='+pesquisa+'&c=apps&hl=pt_BR')
    #https://play.google.com/store/search?q=gta%20e&c=apps&hl=pt_BR&gl=US
    r.html.render(sleep = 0.5)

    html = BeautifulSoup(r.html.html, 'html.parser')
    todos_resultados = []
    
    for link in html.find_all('a', attrs={'class': 'Si6A0c Gy4nib'}):
        todos_resultados.append('https://play.google.com' + link['href'] + '&c=apps&hl=pt_BR')
    
    #print(todos_resultados)

    print(f'Quantidade encontrada: {len(todos_resultados)} - Aplicativos')
    print('--------------------------------------------------------------')

    Base_de_dados = []		
    Link_Google = []
    DIR_IMAGEM_APP = []
    Nome_do_app = []
    Ultima_atualização = []
    Preço = []
    Downloads = []
    palavra_chave = []	
    Idade = []
    Finalidade = []  	
    Nota_app = []
    cont = 0

    qtd_apps_pesquisados = int(input("\nQuantos apps deseja: "))

    for i in range(0, qtd_apps_pesquisados):
        pagina_escolhida = s.get(todos_resultados[i])
        pagina_escolhida.html.render(sleep = 0.5)
        html = BeautifulSoup(pagina_escolhida.html.html, 'html.parser')
        print(f'\n-------------------- Aplicativo - Num: {i+1} -------------------------')
        
        Base_de_dados.append('Play Store')
        #print(f'Loja: {Base_de_dados[i]}')
        
        Link_Google.append(todos_resultados[i])
        #print(f'Link: {Link_Google[i]}')
        
        Nome_do_app.append(html.find('h1', attrs={'itemprop' : 'name'}).text.strip())
        #print(f'Nome: {Nome_do_app[i]}')

        #DIR_IMAGEM_APP.append(download_img(html, Nome_do_app[i], i))
        
        Ultima_atualização.append(html.find('div', attrs={'class' : 'xg1aie'}).text.strip())
        #print(f'Ultima atualização: {Ultima_atualização[i]}')

        Preço.append(valida_preco(html))
        #print(f'Preço: {Preço[i]}')

        Downloads.append(html.findAll('div', attrs={'class' : 'ClM7O'})[1].text)
        #print(f'Número de Downloads: {Downloads[i]}')
        
        palavra_chave.append(pesquisa)
        #print(f'Palavra Chave: {palavra_chave[i]}')

        Finalidade.append(html.find('div', attrs={'data-g-id' : 'description'}).get_text(separator='\n\n'))
        #print(f'Sobre o jogo: {Finalidade[i]}')

        Idade.append(valida_idade(html))
        #print(f'Classicação Indicativa: {Idade[i]}')
    
        Nota_app.append(valida_nota(html))
        #print(f'Nota: {Nota_app[i]}')

        cont = cont+1
        loading = (100*cont)/qtd_apps_pesquisados
        loading = round(loading, 2)
        print(f'Loading: {loading}%')
        print('-----------------------------------------------------------------')
        
        r.html.render(timeout=10)

    return cont, Base_de_dados, Link_Google, Nome_do_app, Ultima_atualização, Preço, Downloads, palavra_chave, Idade, Finalidade, Nota_app