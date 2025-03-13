from requests_html import HTMLSession #Extração do HTML
from bs4 import BeautifulSoup #Extração dos dados desejados
from download_imagem import download_img
import time
from download_imagem import excluir


def nome_corretamente(string_desejada):
    string = string_desejada
    index = string.find('_Composiçãode:')
    string = string[:index]
    string = string.replace('_', ' - ')
    return string

def link(string):
    return string.startswith("http") or string.startswith("https")

def buscar_partitura(pesquisa):
    s = HTMLSession() #Definição da sessão
    r = s.get('https://www.cifraclub.com.br/?q='+ pesquisa)
    r.html.render(sleep = 0.5) # PRIMEIRO RENDERIZA O SITE

    html = BeautifulSoup(r.html.html, 'html.parser') #TRABALHANDO COM HTML RENDERIZADO
    todos_resultados = html.find('div', attrs={'class': 'gsc-expansionArea'}) #Filtrando as div's
    primeira_musica = todos_resultados.find('a', attrs={'class': 'gs-title'})['href']
    
    musica_escolhida = s.get(primeira_musica)
    musica_escolhida.html.render(sleep = 0.5)
    html = BeautifulSoup(musica_escolhida.html.html, 'html.parser')

    url = html.find('div', attrs={'class': 'g-side'})
    url_pronto = url.find('img')['src']

#--------------------------PEGANDO A LETRA DA MÚSICA--------------------------------------------
    r_sound = s.get(primeira_musica+'imprimir.html#tabs=false&instrument=keyboard')
    r_sound.html.render(sleep = 0.5)
    html = BeautifulSoup(r_sound.html.html, 'html.parser')
    
    nome_musica = html.find('div', attrs={'class': 'cifra_header js-cifra_header'}).text.strip()
    nome_musica_nomearArquivo = nome_musica.replace('\n', '_').replace('/', '').replace(' ', '')
    NOME_FORMATADO = nome_corretamente(nome_musica_nomearArquivo)
    caminho_da_imagem = download_img(url_pronto, NOME_FORMATADO)
    conteudo_paginas = html.findAll('pre')
    folhas = [folha.text for folha in conteudo_paginas]

    paginas = ''.join(folhas)

    return caminho_da_imagem, NOME_FORMATADO, paginas
#-----------------------------------------------------------------------------------------------