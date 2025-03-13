from numpy import linalg

def id_alunos():
    print("\n--------------- Integrantes -----------------------")
    print("Nome: Cleverson Pereira da Silva - TIA: 32198531")
    print("Nome: Felipe Nakandakari dos Santos - TIA: 42104701")
    print("Nome: Gustavo Teixeira dos Santos - TIA: 32197020")
    print("---------------------------------------------------")

def metodo_langrage(procedimento, valor_desejado):
    #---------------- VALORES PELO USUARIO --------------------------------
    if procedimento == 1:
        valores_x = []
        valores_y = []
        qtd_pontos = int(input("\nQuantidade de pontos: "))
        for i in range(qtd_pontos):
            ponto = float(input(f'\nX{i}: '))
            f_ponto = float(input(f'F({i}): '))
            valores_x.append(ponto)
            valores_y.append(f_ponto)
        valor_interpolado = float(input("\nQual valor desejado para interpolação?: "))            
    #--------------------------------------------------------------
    
    #---------------- VALORES FIXO --------------------------------
    elif procedimento == 2:
        valores_x = [55,70,85,100,115,130]
        valores_y = [14.08, 13.56, 13.28, 12.27, 11.30, 10.40]
        qtd_pontos = 6
        valor_interpolado = valor_desejado
    #--------------------------------------------------------------
    coeficientes = []
    
    for k in range(qtd_pontos):
        p = 1
        for j in range(len(valores_x)):
            if (k!=j):
                p = p*(valor_interpolado - valores_x[j])/(valores_x[k]-valores_x[j])
        coeficientes.append(p)
    v_interpolado = 0
    for i in range(len(coeficientes)):
        v_interpolado += valores_y[i]*coeficientes[i]
    print(f'\n\nP({valor_interpolado} = {v_interpolado})')

def metodo_Newton(procedimento, valor_desejado):
    #---------------- VALORES PELO USUARIO --------------------------------
    if procedimento == 1:
        qtd_pontos = int(input("\nQuantidade de pontos desejado: "))
        x, y, tabela = [],[], []
        for i in range(qtd_pontos):
            ponto = float(input(f'\nX{i}: '))
            x.append(ponto)
            f_ponto = float(input(f'F({i}): '))
            y.append(f_ponto)
        x_valor_desejado = float(input("\nPonto X desejado: "))
    #--------------------------------------------------------------        
    
    #---------------- VALORES FIXO --------------------------------    
    elif procedimento == 2:
        qtd_pontos = 6
        x, y, tabela = [55,70,85,100,115,130],[14.08, 13.56, 13.28, 12.27, 11.30, 10.40], []
        x_valor_desejado = valor_desejado
    #--------------------------------------------------------------        
    
    tabela.append(y)
    print("\n--------------- SOLUÇÃO ------------------------")
    passo = 1
    for i in range(qtd_pontos-1):
        ordem = []
        for k in range(len(tabela[i])-1):
            diferenca_dividia = (tabela[i][k+1]-tabela[i][k])/(x[k+passo]-x[k])
            ordem.append(diferenca_dividia)
        tabela.append(ordem)
        passo = passo + 1
    
    for p in range(len(tabela)):
        print(f'Ordem {p}: {tabela[p]}')
    
    aprox = 0
    grau = 0
    print("\n")
    
    for i in range(len(tabela)):
        fator = tabela[i][0]
        for j in range(grau):
            fator *= (x_valor_desejado - x[j])
        grau = grau + 1
        aprox = aprox + fator
    
    print(f"\nF({x_valor_desejado}) ≈ {aprox}")
    print("----------------------------------------------------")

def metodo_sistema_linear(procedimento, valor_desejado): 
    #---------------- VALORES PELO USUARIO --------------------------------
    if procedimento == 1:
        qtd_pontos = int(input("\nQuantidade de pontos desejado: "))
        x_list, y_list = [], []
        for k in range(qtd_pontos):
            ponto = float(input(f'\nX{k}: '))
            x_list.append(ponto)
            f_ponto = float(input(f'F({k}): '))
            y_list.append(f_ponto)
        valor_desejado_x = float(input("\nValor de X desejado: "))
    #--------------------------------------------------------------
    
    #---------------- VALORES FIXO --------------------------------
    elif procedimento == 2:
        qtd_pontos = 6
        x_list, y_list = [55,70,85,100,115,130], [14.08, 13.56, 13.28, 12.27, 11.30, 10.40]
        valor_desejado_x = valor_desejado
    #--------------------------------------------------------------
    a, b = [], []
    
    print("\n---------------- SOLUCÃO -----------------------------")
    for i in range(qtd_pontos):
        pot = 0
        grau = qtd_pontos-1
        linha = []
        while pot <= grau:
            coef = pow(x_list[i], pot)
            linha.append(coef)
            pot = pot + 1
        b.append(y_list[i])
        a.append(linha)
    coef_poli = linalg.solve(a, b)

    for j in range(len(coef_poli)):
        print(f'I{j} = {coef_poli[i]}')
    aprox = 0
    for i in range(len(coef_poli)):
        aprox += coef_poli[i]*pow(valor_desejado_x, i)
    print(f"\nF({valor_desejado_x}) ≈ {aprox}")
    print("----------------------------------------------------")

def menu():
    print("\n-------------------")
    print("1. Digitar manualmente")
    print("2. Resolução Exercicio")
    print("9. Finalizar o programa!")
    print("-------------------\n")

def menu_1():
    print("\n-------------------")
    print("1. Resolução de sistemas Lineares")
    print("2. Polinômio interpolador de Lagrange")
    print("3. Polinômio Interpolador de Newton.")
    print("-------------------\n")

def menu_2():
    print("\n-------------------")
    print("1. RESOLUÇÃO EX 2 - Sistemas Lineares (A - 80) (B - 105)")
    print("2. RESOLUÇÃO EX 2 - Interpolador de Lagrange (A - 80) (B - 105)")
    print("3. Resolução EX 2 - Interpolador de Newton (A - 80) (B - 105)")
    print("-------------------\n")


# -------------------- MAIN ----------------------
id_alunos()
while(1):
    menu()
    opcao_menu = int(input("Digite a opção desejada: "))
    if opcao_menu == 1:
        menu_1()
        opcao_menu_1 = int(input("Digite a opção desejada: "))
        if opcao_menu_1 == 1:
            metodo_sistema_linear(1, 0)
        elif opcao_menu_1 == 2:            
            metodo_langrage(1, 0)
        elif opcao_menu_1 == 3:
            metodo_Newton(1, 0)
    elif opcao_menu == 2:
        menu_2()
        opcao_menu_2 = int(input("Digite a opção desejada: "))
        if opcao_menu_2 == 1:
            metodo_sistema_linear(2, 80)
            metodo_sistema_linear(2, 105)
        elif opcao_menu_2 == 2:
            metodo_langrage(2, 80)
            metodo_langrage(2, 105)
        elif opcao_menu_2 == 3:
            metodo_Newton(2, 80)
            metodo_Newton(2, 105)
    elif opcao_menu == 9:
        print("\n-----------------------------------")
        print("Programa encerrado! Até breve!")
        print("-----------------------------------\n")
        break
# ------------------------------------------------------------------