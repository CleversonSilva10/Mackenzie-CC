from requests_html import HTMLSession #Extração do HTML
from bs4 import BeautifulSoup #Extração dos dados desejados
from search_tabs import *
import time



def top_musicas():
    s = HTMLSession() #Definição da sessão
    r = s.get('https://www.cifraclub.com.br/mais-acessadas/violao/')
    r.html.render(sleep = 0.5) # PRIMEIRO RENDERIZA O SITE
    musicas_prontas = []
    html = BeautifulSoup(r.html.html, 'html.parser')
    todas_musica = html.findAll('span', attrs={'class': 'top-number'})
    for i in todas_musica:
        musicas_prontas.append(str(i.text.strip()).replace('\n', ' - '))
    contagem = musicas_prontas.count('')
    for i in range (0, contagem):
        musicas_prontas.remove('')

    return musicas_prontas[-10:] #NOME DAS 10 MUSICAS - LIST