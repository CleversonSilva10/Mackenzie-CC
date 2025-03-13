from requests_html import HTMLSession
from bs4 import BeautifulSoup


def finalidade(html, link):
    s = HTMLSession()
    url = 'https://play.google.com/store/apps/details?id=com.rockstargames.gtasa&hl=pt_BR'
    #script = """const button = document.querySelector('button[aria-label="Ver mais informações sobre Sobre este jogo"]');button.click();"""
    r = s.get(url)
    r.html.render(sleep=5)
    html = BeautifulSoup(r.html.html, 'html.parser')
    sobre = html.find('div', attrs={'class' : 'bARER'}).text
    sobre = sobre.replace('<br>', str('\n'))
    print(sobre)