from dateutil import parser
import re


def valida_preco(html):
    preco = html.find('span', attrs={'itemprop' : 'offers'}).findAll('meta')[-1]['content']
    if preco == 0 or preco == '0':
        preco = 'Gratuito'
        return preco
    else:
        return preco
    
def valida_idade(html):
    idade = html.find('span', attrs={'itemprop' : 'contentRating'}).text
    resultado = re.sub('[^0-9]', '', idade)
    
    if resultado != '':
        resultado = '+'+resultado
        return resultado
    else:
        resultado = 'Livre'
        return resultado

def valida_nota(html):
    nota = html.find('div', attrs={'class' : 'jILTFe'})
    if nota is not None:
        nota_validado = nota.text
        return nota_validado
    else:
        nota = '0'
        return nota

def config_dia_ano(html):
    ultima_atualizacao = html.find('div', attrs={'class' : 'xg1aie'}).text.strip()
    data_objeto = parser.parse(ultima_atualizacao)
    data_formatada = data_objeto.strftime("%d-%m-%Y")
    return data_formatada