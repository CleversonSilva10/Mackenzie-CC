import metodo_print


def Fase_Eliminacao(matriz, n_linhas):
  posicao_pivo = 0  #POSIÇÃO INCIAL - POSIÇÃO MAIS NOROESTE POSSIVEL
  linha_pivo = 0  #VARIAVEL PARA SABER QUAL LINHA DO PIVÔ
  coluna_realizada = 1  #QUANDO É ZERADO TODOS OS VALORES ABAIXO DO PIVÕ, COLUNA REALIZADA É INCREMETADA

  while (posicao_pivo < (n_linhas - 1)):
    valor_pivo = matriz[posicao_pivo][posicao_pivo]  #PEGAR O VALOR DO PIVÔ
    if valor_pivo != 0:  #ESTE VERIFICAÇÃO É IMPORTANTE, POIS É FORMA QUE SABEMOS QUE PODEMOS ZERAR VALORES ABAIXO, CASO AO CONTRARIO TERIAMOS QUE TROCAMOS A LINHA
      verificacao_linha_abaixo = posicao_pivo + 1
      if verificacao_linha_abaixo < (n_linhas):  #VERIFICANDO SE A PROXIMA LINHA É EXISTENTE
        for j in range(verificacao_linha_abaixo,n_linhas):  # J SERVE PARA PEGAR O VALORES ABAIXO DO PIVÔ,
          numerador = matriz[j][posicao_pivo] # NUMEROS ABAIXO DO PIVÔ SERVEM COMO NUMERADOR!
          for i in range(0, n_linhas + 1): # ESTE LOOP É MESMA COISA - EX: L2 = L2 - ML2* L1
            matriz[j][i] = matriz[j][i] - (numerador /valor_pivo) * matriz[linha_pivo][i]
        metodo_print.print_matriz(matriz, coluna_realizada, 1) #APRESENTAR CADA PASSO DESENVOLVIDO
        posicao_pivo += 1 #AUMENTANDO O VARIAVEL PIVÔ, SEMPRE IREI PEGAR O PIVÔ CORRETO DA MATRIZ
        linha_pivo += 1 #AUMENTANDO O VARIAVEL PIVÔ, DEVEMOS AUMENTAR TAMBÉM VARIAVEL LINHA_PIVÔ
        coluna_realizada += 1 #VARIAVEL SÓ PARA INFORMAR
    else:
      aux = []
      i = posicao_pivo  #POSICÃO ATUAL DO PIVÔ
      j = posicao_pivo + 1  #POSIÇÃO ABAIXO DA LINHA ATUAL

      #SABENDO QUE PIVÔ É ZERO, ESSA É FORMA DE SABER QUAL VALOR ABAIXO É MAIOR PARA PODEMOS FAZER A TROCA DAS LINHAS DA MATRIZ
      while (i < n_linhas and j < n_linhas):
        if matriz[i][posicao_pivo] < matriz[j][posicao_pivo]:
          i += 1
          j += 1
          posicao_troca = j

      #SUBSTITUIÇÃO DAS LINHAS
      for i in range(0, n_linhas):
        aux.append(matriz[posicao_pivo][i])
        matriz[posicao_pivo][i] = matriz[posicao_troca][i]
        matriz[posicao_troca][i] = aux[0][i]


def substituicao(matriz, n_linhas): #
  x = [0]*n_linhas # LISTA X COM N_LINHAS ELEMENTOS IGUAIS A ZERO. ESSA LISTA IRÁ ARMAZENAR A SOLUÇÃO DO SISTEMA LINEAR.
  print(f'---- SOLUÇÃO: ----')
  for i in range(n_linhas-1, -1, -1): #LOOP EXTERNO PERCORRE AS LINHAS DA MATRIZ DE TRÁS PARA FRENTE, INICIANDO DA ÚLTIMA LINHA E INDO ATÉ A PRIMEIRA. ESSE LOOP IRÁ RESOLVER A SOLUÇÃO DO SISTEMA LINEAR PASSO A PASSO.
    soma = 0
    for j in range(i+1, n_linhas): #LOOP INTERNO IRÁ CALCULAR A SOMA DOS PRODUTOS DOS ELEMENTOS DA MATRIZ[I][J] PELA SOLUÇÃO JÁ ENCONTRADA (X[J]).
      soma += matriz[i][j] * x[j]
    #CALCULA A SOLUÇÃO X[I] PARA A LINHA ATUAL (I)
    x[i] = (matriz[i][n_linhas]-soma)/matriz[i][i]
    print(f"x{i+1} = {round(x[i], 2)}.")
  print('----------------------')    
