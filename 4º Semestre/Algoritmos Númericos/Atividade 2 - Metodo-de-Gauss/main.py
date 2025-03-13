#Cleverson Pereira da Silva  TIA: 32198531
#Gustavo Teixeira dos Santos  TIA: 32197020
# Algoritmo para resolver sistemas lineares baseado no método da eliminação de Gauss

import generate_table
import Gauss_Pivotamento
import metodo_print

if __name__ == "__main__":
  metodo_print.integrantes()
  ativo = True

  while (ativo != False):
    print('------------MENU--------------')
    print('1. Digitar manualmente')
    print('2. Resolução do exercício 3')
    print('0. Finalizar o programa')
    print('------------------------------')
    x = int(input('\nQual opções deseja escolher?: '))    
    if x == 1:
      qnt_equacoes = int(input("Digite quantas equações lineares você deseja inserir: "))
      equacoes = []
      for equacao in range(qnt_equacoes):
        equacoes.append(str(input("Digite a {} equação: ".format(equacao + 1))).replace(' ', ''))

      result = generate_table.monta_tabela(equacoes)
      if result == False:
        print("Esse sistema é inválido")
        exit()
      tabela = result[0]
      variaveis = result[1]

      metodo_print.print_matriz(tabela, 0, 0)
      Gauss_Pivotamento.Fase_Eliminacao(tabela, len(tabela))
      Gauss_Pivotamento.substituicao(tabela, len(tabela))

    elif x == 2: 
      ex3 = [
        [1, 0, 2, 3, 2, 1, 0, 2, 37],
        [1, 1, 1, 2, 1, 0, 3, 0, 26],
        [1, 2, 1, 1, 2, 2, 1, 1, 40],
        [0, 1, 2, 2, 3, 4, 2, 1, 45],
        [2, 1, 0, 1, 1, 3, 1, 2, 37],
        [1, 1, 1, 1, 1, 1, 1, 0, 23],
        [1, 2, 3, 1, 0, 2, 2, 1, 35],
        [0, 2, 1, 1, 1, 0, 2, 0, 24],
      ]

      metodo_print.print_matriz(ex3, 0, 0)
      Gauss_Pivotamento.Fase_Eliminacao(ex3, len(ex3))
      Gauss_Pivotamento.substituicao(ex3, len(ex3))
    
    elif x == 0: 
      print(f'\n\nObrigado por usar nossa calculadora de Eliminação de Gauss')
      print(f'Programa finalizado!\n\n')
      ativo = False
    
