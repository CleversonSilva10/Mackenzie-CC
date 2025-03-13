import random
import time
import copy

def id_alunos():
    print(f'\n\033[32m'+'Autor do código'+'\033[0;0m')
    print('-' * 90)
    print(f'Nome: Cleverson Pereira da Silva | TIA: 32198531')
    print(f'ALGORITMOS E PROGRAMACAO II [Turma 02N11] - 2022/1 | Universidade Presbiteriana Mackenzie')
    print('-' * 90)
id_alunos()

def menu():
    print('\n\033[33m'+'Menu'+'\033[0;0m')
    print(f'1 - Ver scores')
    print(f'2 - Iniciar o jogo')
    print(f'3 - Finalizar o jogo')
    print(f'4 - Regras do jogo\n')

def menu_nivel():
    print('\n\033[33m'+'Selecione a dificuldade'+'\033[0;0m')
    print(f'1 - Fácil')
    print(f'2 - Médio')
    print(f'3 - Difícil\n')
    
#--------------------------------- Preenchimento dos vencedores de cada nivel txt ---------------------------------------#
def score(nome, tentativas):
    with open('score.txt', "a") as arq:
        if nivel_jogador == 1:
            if arq.readline == 'Dados dos jogadores:':
                arq.write(f'Nome: {nome} - Número de tentativas: {tentativas} - Dificuldade: Fácil\n')
            else:
                arq.write(f'Nome: {nome} - Número de tentativas: {tentativas} - Dificuldade: Fácil\n')
        elif nivel_jogador == 2:
            if arq.readline == 'Dados dos jogadores:':
                arq.write(f'Nome: {nome} - Número de tentativas: {tentativas} - Dificuldade: Médio\n')
            else:
                arq.write(f'Nome: {nome} - Número de tentativas: {tentativas} - Dificuldade: Médio\n')
        elif nivel_jogador == 3:
            if arq.readline == 'Dados dos jogadores:':
                arq.write(f'Nome: {nome} - Número de tentativas: {tentativas} - Dificuldade: Difícil\n')
            else:
                arq.write(f'Nome: {nome} - Número de tentativas: {tentativas} - Dificuldade: Difícil\n')
#---------------------------------------------------------------------------------------------------------------------#
#--------------------------------------- Leitura do Placar Lider -----------------------------------------------------#
def verscore():
    with open('score.txt', "r") as arq_leitura:
        print()
        for i in arq_leitura:
            print(i)
            time.sleep(1.0)
#---------------------------------------------------------------------------------------------------------------------#
#--------------------------------------- Leitura dos jogos possiveis -------------------------------------------------#
def leitura():
    lista_linhas = []
    with open('desafiotxt.txt', 'r', encoding='utf-8') as arquivo:
        for linha in arquivo.readlines():
            linha = linha.strip()
            if len(linha) >= 1:
                lista_linhas.append(list(linha))
    return lista_linhas
#---------------------------------------------------------------------------------------------------------------------#
def regras_jogo():
    print(f'\n\033[36m'+'                               Regras do jogo   '+'\033[0;0m')
    time.sleep(1.5)
    print(f'1ª Regra - Cada linha deve conter os números de 1 a 4, sem repetições.')
    time.sleep(1.5)
    print(f'2ª Regra - Os números de 1 a 4 apenas podem estar presentes uma vez por coluna.')
    time.sleep(1.5)
    print(f'3ª Regra - Cada dígito apenas pode estar presente uma vez por grupo.')
    time.sleep(1.5)
    print(f'4ª Regra - O valor da soma de cada linha, coluna e grupo é de 10.')
    time.sleep(1.5)
#----------------------------------- Função para subdivisão da lista - Matriz ----------------------------------------#
def listasMenores(lista, n):
  for i in range(0, len(lista), n):
     yield lista[i:i+n]
#---------------------------------------------------------------------------------------------------------------------#
#----------------------------------- Função para visualização do jogo ------------------------------------------------#
def mostrar(v):
    print(f'\n\033[34m'+' SUDOKU MINI 4x4 '+'\033[0;0m')
    print(f'_'*13)
    print(f'\n\033[33m'+'  C0 C1 C2 C3'+'\033[0;0m')
    print(f'\033[33m'+'L0' +'\033[0;0m' f' {v[0][0]} {v[0][1]} | {v[0][2]}  {v[0][3]}')
    print(f'\033[33m'+'L1' +'\033[0;0m' f' {v[1][0]} {v[1][1]} | {v[1][2]}  {v[1][3]}')
    print(f'   ----+-----')
    print(f'\033[33m'+'L2' +'\033[0;0m' f' {v[2][0]} {v[2][1]} | {v[2][2]}  {v[2][3]}')
    print(f'\033[33m'+'L3' +'\033[0;0m' f' {v[3][0]} {v[3][1]} | {v[3][2]}  {v[3][3]}')
#---------------------------------------------------------------------------------------------------------------------#
#-------------------------------- Verificações dos input's feitos pelo jogador ---------------------------------------#
def verificacao_linha(linha_j):
    if linha_j >= 0 and linha_j <= 3:
        return linha_j
    else:
        print(f'\n\033[31m'+'Por favor, digite novamente o valor da linha entre 0 a 3'+'\033[0;0m')
        linha_novamente = int(input(f'Digite valor novamente da linha: '))
        return verificacao_coluna(linha_novamente)
def verificacao_coluna(coluna_j): 
    if coluna_j >= 0 and coluna_j <= 3:
        return coluna_j
    else:
        print(f'\n\033[31m'+'Por favor, digite novamente o valor da coluna entre 0 a 3'+'\033[0;0m')
        coluna_novamente = int(input(f'Digite valor novamente da coluna: '))
        return verificacao_coluna(coluna_novamente)
def verificacao_valor(valor_j):
    if valor_j >= 1 and valor_j <= 4:
        return valor_j
    else:
        print(f'\n\033[31m'+'- Por favor, digite novamente o valor entre 1 a 4 -'+'\033[0;0m')
        valor_novamente = int(input(f'Digite valor novamente da valor: '))
        return verificacao_valor(valor_novamente)
#---------------------------------------------------------------------------------------------------------------------#
#-------------------------------- Funções para resolução do sudoku ---------------------------------------------------#
def vazio(sudoku_resolvido):
    for linha in range(4): #Percorrendo a linha da matriz
        for coluna in range(4): #Percorrendo a coluna da matriz
            if sudoku_resolvido[linha][coluna] == '.':
                return linha, coluna
    return -1,-1
def num_valido(valor, linha, coluna, sudoku_resolvido):
    for i in range(4):
        if sudoku_resolvido[linha][i] == valor:
            return False #Caso encontre um valor igual na linha, valor não pode ser inserido
    for j in range(4):
        if sudoku_resolvido[j][coluna] == valor:
            return False #Caso encontre um valor igual na coluna, valor não pode ser inserido
    i=linha//2
    j=coluna//2
    for m in range(i*2, i*2+2):
        for n in range(j*2, j*2+2):
            if sudoku_resolvido[m][n] == valor:
                return False
    return True

def solucionador_sudoku(sudoku_resolvido):
    linha, coluna = vazio(sudoku_resolvido)
    if linha == -1 and coluna == -1:
        return True
    else:
        for i in range(1, 5):
            if num_valido(i, linha, coluna, sudoku_resolvido):
                sudoku_resolvido[linha][coluna] = i
                if solucionador_sudoku(sudoku_resolvido):
                    return True
                sudoku_resolvido[linha][coluna] = 0               
    return False
#---------------------------------------------------------------------------------------------------------------------#
#------------------------------------------ Verificações finais ------------------------------------------------------#
def sudoku_check(lista_dividida, linha_j, coluna_j, valor_j, resolucao):
    if lista_dividida[verificacao_linha(linha_j)][verificacao_coluna(coluna_j)] == '.':
        lista_dividida[verificacao_linha(linha_j)][verificacao_coluna(coluna_j)] = verificacao_valor(valor_j)
        mostrar(lista_dividida)
    elif lista_dividida[verificacao_linha(linha_j)][verificacao_coluna(coluna_j)] == 1 or lista_dividida[verificacao_linha(linha_j)][verificacao_coluna(coluna_j)] == 2 or lista_dividida[verificacao_linha(linha_j)][verificacao_coluna(coluna_j)] == 3 or lista_dividida[verificacao_linha(linha_j)][verificacao_coluna(coluna_j)] == 4:
        print(f'\n\033[31m'+'Essa jogada não pode ser efetuada, tente novamente!'+'\033[0;0m')
        return 1
def desistir_resolucao(abandonar):
    if abandonar == 'S':
        return 1 #Continuar
    if abandonar == 'Q':
        print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
        print(f'\n\033[31m'+'           Resolução          '+'\033[0;0m')
        solucionador_sudoku(resolucao)
        mostrar(resolucao)
        print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
        return 2 #Irá interromper o while
#---------------------------------------------------------------------------------------------------------------------#
#-------------------------- Substituição das strings pelo valores inteiros -------------------------------------------#
def string_int(lista_dividida):
    for i in range(0,4):
        for j in range(0,4):
            if lista_dividida[i][j] == '1': #Subtituição da string pelo número inteiro 1
                lista_dividida[i][j] = 1
            if lista_dividida[i][j] == '2': #Subtituição da string pelo número inteiro 2
                lista_dividida[i][j] = 2
            if lista_dividida[i][j] == '3': #Subtituição da string pelo número inteiro 3
                lista_dividida[i][j] = 3
            if lista_dividida[i][j] == '4': #Subtituição da string pelo número inteiro 4
                lista_dividida[i][j] = 4
#---------------------------------------------------------------------------------------------------------------------#
lista_pronta = leitura() #Apuração de todos os jogos possiveis e alocando em cada elemento da lista
nivel_facil = [] #Jogos - Easy
nivel_medio = [] #Jogos - Medium
nivel_dificil = [] #Jogos - Hard
#----------------------------------- Classificando a dificuldade dos jogos -------------------------------------------#
for i in lista_pronta:
    qtdade_numeros = len(i)-i.count('.')
    if qtdade_numeros >= 4 and qtdade_numeros <= 6:
        nivel_dificil.append(i) #Adicionado 
    elif qtdade_numeros >= 7 and qtdade_numeros <=8:
        nivel_medio.append(i)
    elif qtdade_numeros >= 9 and qtdade_numeros <=15:
        nivel_facil.append(i)
#---------------------------------------------------------------------------------------------------------------------#
#Opção escolhida pelo jogador
finalizar = 1
jogo_em_andamento = True
while finalizar == 1:
    menu()
    opcao = int(input(f'\n\033[34m'+'Digite a opção desejada: '+'\033[0;0m'))
    #-------------------------- Opção 1 -------------------------------------------#
    if opcao == 1:
        verscore()
    #-------------------------- Opção 2 -------------------------------------------#        
    if opcao == 2:
        menu_nivel()
        nivel_jogador = int(input(f'\n\033[34m'+'Escolha a dificuldade desejada: '+'\033[0;0m'))
        #Nivel escolhido pelo jogador
        #-------------------------- Nivel Fácil -------------------------------------------#
        if nivel_jogador == 1:
                resolucao = [[0,0,0,0], [0,0,0,0], [0,0,0,0], [0,0,0,0]]
                nivel_facil_random = random.choice(nivel_facil) #De forma aleatoria escolher um jogo dentro da lista facil
                lista_dividida = list(listasMenores(nivel_facil_random, 4)) #Dividi a lista em uma matriz 4x4
                string_int(lista_dividida) #Strings '1','2','3' e '4' subtituidas por valores inteiros
                for i in range(4):
                    for j in range(4):
                        resolucao[i][j] = lista_dividida[i][j]
                mostrar(lista_dividida)
                tentativas = 0 #Inicialização das tentativas
                start_time = time.time() #Inicialização do tempo de jogo
                while jogo_em_andamento == 1: #Enquanto as funções retornarem 1, while continua. Quando retornar 2, quebra o while.
                    linha_j = int(input(f'\n\033[33m'+'Digite a linha desejada entre 0 e 3: '+'\033[0;0m')) #Insira valor da linha
                    coluna_j = int(input(f'\n\033[33m'+'Digite a coluna desejada entre 0 e 3: '+'\033[0;0m')) #Insira valor da coluna
                    valor_j = int(input(f'\n\033[33m'+'Digite o valor desejado entre 1 e 4: '+'\033[0;0m')) #Insira valor
                    verificacao_linha(linha_j) # Verificações para manter while
                    verificacao_coluna(coluna_j) # Verificações para manter while
                    verificacao_valor(valor_j) # Verificações para manter while
                    solucionador_sudoku(resolucao) #Resolução do sudoku proposto
                    tentativas += 1 # Caso as verificações retornarem 1, contaram uma tentativa
                    print(f'\n\033[36m'+'Número de tentativas:'+'\033[0;0m', tentativas)
                    abandonar = input(f'\nDigite S - Continuar\nDigite Q - Desistir e ver resolução\nQual opção?: ').upper()
                    jogo_em_andamento = sudoku_check(lista_dividida, verificacao_linha(linha_j), verificacao_coluna(coluna_j), verificacao_valor(valor_j), resolucao)
                    jogo_em_andamento = desistir_resolucao(abandonar)
                    if '.' not in lista_dividida[0] and '.' not in lista_dividida[1] and '.' not in lista_dividida[2] and '.' not in lista_dividida[3]:
                        if lista_dividida == resolucao:
                            print(f'\n\033[32m'+'           Você conseguiu resolver sudoku, parabéns!          '+'\033[0;0m')
                            end_time = time.time()
                            cronometro = end_time - start_time
                            tempo_adequeado = round(cronometro, 2)
                            print(f'\n\033[32m'+'Tempo jogado:'+'\033[0;0m', tempo_adequeado, f'segundos')
                            nome = input(f'\n\033[34m'+'Digite seu nome: '+'\033[0;0m')
                            score(nome, tentativas)
                            jogo_em_andamento = 2
                        elif lista_dividida != resolucao:
                            print(f'\n\033[31m'+'           Desculpe, mas sudoku está incorreto          '+'\033[0;0m')
                            print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
                            print(f'\n\033[31m'+'           Resolução correta          '+'\033[0;0m')
                            mostrar(resolucao)
                            print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
                            jogo_em_andamento = 2
        #----------------------------------------------------------------------------------#
        #-------------------------- Nivel Médio -------------------------------------------#
        elif nivel_jogador == 2:
                nivel_medio_random = random.choice(nivel_medio) #De forma aleatoria escolher um jogo dentro da lista facil
                lista_dividida = list(listasMenores(nivel_medio_random, 4)) #Dividi a lista em uma matriz 4x4
                string_int(lista_dividida) #Strings '1','2','3' e '4' subtituidas por valores inteiros
                for i in range(4):
                    for j in range(4):
                        resolucao[i][j] = lista_dividida[i][j]
                mostrar(lista_dividida)
                tentativas = 0 #Inicialização das tentativas
                pontos_por_jogada_certa = 0 #Inicialização da contagem dos pontos
                start_time = time.time() #Inicialização do tempo de jogo
                while jogo_em_andamento == 1:
                    linha_j = int(input(f'\n\033[33m'+'Digite a linha desejada entre 0 e 3: '+'\033[0;0m')) #Insira valor da linha
                    coluna_j = int(input(f'\n\033[33m'+'Digite a coluna desejada entre 0 e 3: '+'\033[0;0m')) #Insira valor da coluna
                    valor_j = int(input(f'\n\033[33m'+'Digite o valor desejado entre 1 e 4: '+'\033[0;0m')) #Insira valor
                    verificacao_linha(linha_j) # Verificações para manter while
                    verificacao_coluna(coluna_j) # Verificações para manter while
                    verificacao_valor(valor_j) # Verificações para manter while
                    solucionador_sudoku(resolucao) #Resolução do sudoku proposto
                    tentativas += 1 # Caso as verificações retornarem 1, contaram uma tentativa
                    print(f'\n\033[36m'+'Número de tentativas:'+'\033[0;0m', tentativas)
                    abandonar = input(f'\nDigite S - Continuar\nDigite Q - Desistir e ver resolução\nQual opção?: ').upper()
                    jogo_em_andamento = sudoku_check(lista_dividida, verificacao_linha(linha_j), verificacao_coluna(coluna_j), verificacao_valor(valor_j), resolucao)
                    jogo_em_andamento = desistir_resolucao(abandonar)
                    if '.' not in lista_dividida[0] and '.' not in lista_dividida[1] and '.' not in lista_dividida[2] and '.' not in lista_dividida[3]:
                        if lista_dividida == resolucao:
                            print(f'\n\033[32m'+'           Você conseguiu resolver sudoku, parabéns!          '+'\033[0;0m')
                            end_time = time.time()
                            cronometro = end_time - start_time
                            tempo_adequeado = round(cronometro, 2)
                            print(f'\n\033[32m'+'Tempo jogado:'+'\033[0;0m', tempo_adequeado, f'segundos')
                            nome = input(f'\n\033[34m'+'Digite seu nome: '+'\033[0;0m')
                            score(nome, tentativas)
                            jogo_em_andamento = 2
                        elif lista_dividida != resolucao:
                            print(f'\n\033[31m'+'           Desculpe, mas sudoku está incorreto          '+'\033[0;0m')
                            print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
                            print(f'\n\033[31m'+'           Resolução correta          '+'\033[0;0m')
                            mostrar(resolucao)
                            print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
                            jogo_em_andamento = 2
         #------------------------------------------------------------------------------------#
         #-------------------------- Nivel Difícil -------------------------------------------#                        
        elif nivel_jogador == 3:
                nivel_dificil_random = random.choice(nivel_dificil) #De forma aleatoria escolher um jogo dentro da lista facil
                lista_dividida = list(listasMenores(nivel_dificil_random, 4)) #Dividi a lista em uma matriz 4x4
                string_int(lista_dividida) #Strings '1','2','3' e '4' subtituidas por valores inteiros
                for i in range(4):
                    for j in range(4):
                        resolucao[i][j] = lista_dividida[i][j]
                mostrar(lista_dividida)
                tentativas = 0 #Inicialização das tentativas
                pontos_por_jogada_certa = 0 #Inicialização da contagem dos pontos
                start_time = time.time() #Inicialização do tempo de jogo
                while jogo_em_andamento == 1:
                    linha_j = int(input(f'\n\033[33m'+'Digite a linha desejada entre 0 e 3: '+'\033[0;0m')) #Insira valor da linha
                    coluna_j = int(input(f'\n\033[33m'+'Digite a coluna desejada entre 0 e 3: '+'\033[0;0m')) #Insira valor da coluna
                    valor_j = int(input(f'\n\033[33m'+'Digite o valor desejado entre 1 e 4: '+'\033[0;0m')) #Insira valor
                    verificacao_linha(linha_j) # Verificações para manter while
                    verificacao_coluna(coluna_j) # Verificações para manter while
                    verificacao_valor(valor_j) # Verificações para manter while
                    solucionador_sudoku(resolucao) #Resolução do sudoku proposto
                    tentativas += 1 # Caso as verificações retornarem 1, contaram uma tentativa
                    print(f'\n\033[36m'+'Número de tentativas:'+'\033[0;0m', tentativas)
                    abandonar = input(f'\nDigite S - Continuar\nDigite Q - Desistir e ver resolução\nQual opção?: ').upper()
                    jogo_em_andamento = sudoku_check(lista_dividida, verificacao_linha(linha_j), verificacao_coluna(coluna_j), verificacao_valor(valor_j), resolucao)
                    jogo_em_andamento = desistir_resolucao(abandonar)
                    if '.' not in lista_dividida[0] and '.' not in lista_dividida[1] and '.' not in lista_dividida[2] and '.' not in lista_dividida[3]:
                        if lista_dividida == resolucao:
                            print(f'\n\033[32m'+'           Você conseguiu resolver sudoku, parabéns!          '+'\033[0;0m')
                            end_time = time.time()
                            cronometro = end_time - start_time
                            tempo_adequeado = round(cronometro, 2)
                            print(f'\n\033[32m'+'Tempo jogado:'+'\033[0;0m', tempo_adequeado, f'segundos')
                            nome = input(f'\n\033[34m'+'Digite seu nome: '+'\033[0;0m')
                            score(nome, tentativas)
                            jogo_em_andamento = 2
                        elif lista_dividida != resolucao:
                            print(f'\n\033[31m'+'           Desculpe, mas sudoku está incorreto          '+'\033[0;0m')
                            print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
                            print(f'\n\033[31m'+'           Resolução correta          '+'\033[0;0m')
                            mostrar(resolucao)
                            print(f'\n\033[31m'+'---------------------------'+'\033[0;0m')
                            jogo_em_andamento = 2 
        #------------------------------------------------------------------------------------#
    #-------------------------- Opção 3 -------------------------------------------#                
    elif opcao == 3:
        time.sleep(0.6)
        print(f'\033[31m'+'Saindo do jogo!'+'\033[0;0m')
        time.sleep(0.6)
        print(f'\033[31m'+'Obrigado por jogar, até breve!'+'\033[0;0m\n')
        finalizar = 0
    #-------------------------- Opção 4 -------------------------------------------#  
    elif opcao == 4:
        regras_jogo()