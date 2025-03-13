def integrantes():
  print('\n\nDisciplina: Algoritmos Numéricos - Professora: Profa. Dra. Débora Bezerra L. Libório')
  print('Turma: 04N - Semestre: 01/2023\nAtividade 2 – Eliminação de Gauss\n')
  print('--------------------------------------------------')
  print('Nome: Cleverson Pereira da Silva - TIA: 32198531')
  print('Nome: Gustavo Teixeira dos Santos - TIA: 32197020')
  print('--------------------------------------------------\n')


def print_matriz(matriz, coluna_realizada, comando):
  if comando == 0:
    print(f'\n--- MATRIZ ORIGINAL ---')
    for linha in matriz:
      for valor in linha:
        print(f"{valor:.2f}  ", end="")
      print("")
    print('----------------------')
    print("\n")
  elif comando == 1:
    print(f'--- {coluna_realizada}: Matriz ----')
    for linha in matriz:
      for valor in linha:
        print(f"{valor:.2f}  ", end="")
      print("")
    print('----------------------')
    print("\n")
  elif comando == 2:
    print(f'--- MATRIZ FINALIZADA ---')
    for linha in matriz:
      for valor in linha:
        print(f"{valor:.2f}  ", end="")
      print("")
    print('----------------------')
    print("\n\n")
