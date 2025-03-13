import random
import time

def id_alunos():
    print(f'\n\033[32m'+'Autores do código'+'\033[0;0m')
    print('-' * 90)
    print(f'Nome: Cleverson Pereira da Silva | TIA: 32198531')
    print(f'Nome: Lucas Araújo Martins da Silva | TIA: 42009235')
    print(f'Prof. Ms.: Tomaz Mikio Sasaki | ALGORITMOS E PROGRAMACAO II [Turma 02N11] - 2022/1')
    print('-' * 90)
id_alunos()

def legenda():
    print('\033[33m'+'\nProjeto 1 - Descubra a palavra'+'\033[0;0m')
    print(f'Informações para o "Player" - Instruções sobre o jogo:')
    print('-' * 90)
    print(f'^ - Faz parte da palavra e está na posição correta.')
    print(f'X - Não fazem parte da palavra.')
    print(f'! - Faz parte da palavra mas não está na posição correta.')
    print('-' * 90)
legenda()

def menu():
    print('\n\033[33m'+'Bem vindo! - Menu'+'\033[0;0m')
    print(f'1 - Iniciar o Jogo')
    print(f'2 - Finalizar o Jogo\n')

def leitura_txt():
    with open(r"C:\Users\Cleverson Silva\Documents\My Codes\PROJETO\sem_acentos.txt", "r") as arq:
        palavras_txt = arq.read().splitlines()  # Realizando a leitura do documento
        palavras_lista = list(palavras_txt)
        return palavras_lista
leitura_txt()

def score(nome, entrada_v, tentativas, tempo_s):
    with open(r"C:\Users\Cleverson Silva\Documents\My Codes\PROJETO\scores.txt", "a") as arq:
        if arq.readline == 'Dados dos jogadores:':
            arq.write(f'\n Nome: {nome}\n Palavra sorteada: {entrada_v}\n Número de tentativas: {tentativas}')
        else:
            arq.write(f'\n Nome: {nome}\n Palavra sorteada: {entrada_v}\n Número de tentativas: {tentativas}\n Tempo total (s): {tempo_s} ')

def verifica_palavra_dicionario(entrada):
    while True:
        if contem(palavras_adequadas, entrada_jogador) and len(entrada_jogador) == 5:
            print(f'\nEstá palavra contêm no dicionário estabelecido')
            return True
        else:
            print(f'\nEstá palavra não pode ser utilizada. Tente novamente!')
            return False

def contem(v, e):
  for i in range((len(v))):
    if e == v[i]:
      return True
  return False

palavras_adequadas = []
palavras_lista = leitura_txt()
for k in palavras_lista:
    if len(k) == 5:
        palavras_adequadas.append(k)

ganhou = False
simbolo = [" "]*5
inicio = time.time()

sair = False
finalizar = 1
while finalizar == 1:
    menu()
    op = input('\033[33m'+'Digite a opção desejada: '+'\033[0;0m')
    if op == '1':
        palavra_sorteada = list(random.choice(palavras_adequadas))
        #print(palavra_sorteada)
        tentativas = 6
        while tentativas > 0:
            entrada_jogador = input('\033[32m'+'Digite uma palavra que contêm cinco letras: '+'\033[0;0m').lower()
            entrada_verificada = list(entrada_jogador)
            if verifica_palavra_dicionario(entrada_jogador):
                tentativas = tentativas-1
                print('\033[33m'+'Você possui', tentativas, 'tentativas'+'\033[0;0m\n')
                for k in range(0, 5):
                    if palavra_sorteada[k] == entrada_verificada[k]:
                        simbolo[k] = '^'
                    elif contem(palavra_sorteada, entrada_verificada[k]):
                        simbolo[k] = '!'
                    else:
                        simbolo[k] = 'X'
                print('-'*25)
                print(entrada_verificada)
                print(simbolo)
                print('-'*25)
                if palavra_sorteada == entrada_verificada:
                    print(f'\033[32m'+'Parabéns, você acertou a palavra sorteada!!!\n'+'\033[0;0m', end="")
                    nome_jogador = input("Digite seu nome: ")
                    tentativas_ = 6 - tentativas
                    final = time.time()
                    tempo = final - inicio
                    tempo_adequeado = round(tempo, 3)
                    score(nome_jogador, entrada_verificada, tentativas_, tempo_adequeado)
                    tentativas = 0
                    ganhou = True
        if ganhou == False:
            print(f'A palavra sorteada é {palavra_sorteada}')
    elif op == '2':
        print(f'\n\033[31m'+'Saindo do jogo!'+'\033[0;0m')
        time.sleep(0.6)
        print(f'\033[31m'+'Obrigado por jogar, até breve!'+'\033[0;0m')
        finalizar = finalizar-1