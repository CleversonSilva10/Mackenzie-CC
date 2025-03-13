import math 

def id_alunos():
    print("\n--------------- Integrantes -----------------------")
    print("Nome: Cleverson Pereira da Silva - TIA: 32198531")
    print("Nome: Felipe Nakandakari dos Santos - TIA: 42104701")
    print("Nome: Gustavo Teixeira dos Santos - TIA: 32197020")
    print("---------------------------------------------------")

#------------- Método Secante ---------------------------------
def inserir_valores_inicias(StringFormula , List_X, Valor_de_X_Funcao):
    X0 = float(input("\nIntervalo 1: "))
    X1 = float(input("Intervalo 2: "))
    List_X.append(X0)
    List_X.append(X1)
    Valor_de_X_Funcao.append(Funcao_Principal(StringFormula, List_X[0]))
    Valor_de_X_Funcao.append(Funcao_Principal(StringFormula, List_X[1]))

def Funcao_Principal(StringFormula, valor_desejado):
    Formula = StringFormula
    cos_ = math.cos(valor_desejado)
    Formula = Formula.replace('t', str(valor_desejado))
    Formula = Formula.replace('cos-x', str(cos_))
    Formula = Formula.replace('x', str(valor_desejado))
    Formula = Formula.replace('e', str(2.718281828))
    return eval(Formula)

def metodo_secante(StringFormula, x_anterior, x_ant_anterior):
    Funcao_X_anterior = Funcao_Principal(StringFormula, x_anterior)
    Funcao_X_Ant_anterior = Funcao_Principal(StringFormula, x_ant_anterior)
    formula_secante = x_anterior - ((Funcao_X_anterior*(x_anterior-x_ant_anterior))/(Funcao_X_anterior-Funcao_X_Ant_anterior))
    return formula_secante
#------------------------------------------------------------
#------------- Método Bissecção ---------------------------------
def metodo_da_bisseccao(a, b):
    resultado = (a+b)/2
    return resultado

def funcao_principal_bisseccao(StringFormula, x):
    Formula = StringFormula
    cos_ = math.cos(x)
    Formula = Formula.replace('t', str(x))
    Formula = Formula.replace('cos-x', str(cos_))
    Formula = Formula.replace('x', str(x))
    Formula = Formula.replace('e', str(2.718281828))

    return eval(Formula)
#------------------------------------------------------------

def operadores_aritmeticos():
    print("\n +	Adição.")
    print(" -	Subtração.")
    print(" *	Multiplicação.")
    print(" /	Divisão.")
    print(" **	Exponenciação.")
    print(" e	Valor Euller = 2.718281828")
    print(" cos-x	Irá calcular cos(x)")

#-------------------------------------------------
def menu():
    print("\n-------------------")
    print("1. Digitar manualmente")
    print("2. Resolução - Exercicio 2")
    print("9. Finalizar o programa!")
    print("-------------------\n")

def menu_digitar():
    print("\n-------------------")
    print("1. Manualmente - Metodo da Secante")
    print("2. Manualmente - Metodo da Bissecção")
    print("-------------------\n")

def Resolucao_Ex2():
    print("\n-------------------")
    print("1. Resolução Exercicio 2 - Metodo da Secante")
    print("2. Resolução Exercicio 2 - Metodo da Bissecção")
    print("-------------------\n")

#----------- MAIN -------------------------------------
id_alunos()
fim = False
parou = False

while(fim != True):
    menu()
    opcao_menu = int(input("Digite a opção desejada: "))
    if opcao_menu == 1:
        menu_digitar()
        opcao_menu1 = int(input("Digite a opção desejada: "))
        if opcao_menu1 == 1:
            operadores_aritmeticos()
            StringFormula = input("\nDigite a formula desejada: F(x) = ")
            List_X = []
            Valor_de_X_Funcao = []
            inserir_valores_inicias(StringFormula, List_X, Valor_de_X_Funcao)
            precisao = float(input("Informe a precisão (decimal): "))
            print("\n-------------------")
            print("Metodo da Secante")
            print("-------------------")
            print("\n------------- Tabela de Iterações --------------------")
            print(f'X0 = {List_X[0]:.15f} | F(X0) = {Valor_de_X_Funcao[0]:.15f}')
            print(f'X1 = {List_X[1]:.15f} | F(X1) = {Valor_de_X_Funcao[1]:.15f}')
            k = 2
            while(1):
                Novo_X = metodo_secante(StringFormula, List_X[k-1], List_X[k-2])
                List_X.append(Novo_X)
                Resultado_Funcao_X = Funcao_Principal(StringFormula, Novo_X)
                Valor_de_X_Funcao.append(Resultado_Funcao_X)
                print(f'X{k} = {Novo_X:.15f} | F(X{k}) = {Resultado_Funcao_X:.15f}')
                if abs(Resultado_Funcao_X) < precisao:
                    break
                else:
                    k = k+1
            print("------------------------------------------------")
            print(f"\nMenor raiz -> X{k} = {Novo_X}")
            List_X.clear()
            Valor_de_X_Funcao.clear()
        elif opcao_menu1 == 2:
            operadores_aritmeticos()
            StringFormula = input("\nDigite a formula desejada: F(x) = ")
            a = float(input("\nInforme valor de A: "))
            b = float(input("Informe valor de B: "))
            precisao = float(input("Digite a precisão: "))
            print("\n-------------------")
            print("Metodo da Bissecção")
            print("-------------------")
            print("\n------------- Tabela de Iterações --------------------")
            k = 0
            while(1):
                x = metodo_da_bisseccao(a, b)
                F_A = funcao_principal_bisseccao(StringFormula, a)
                F_X = funcao_principal_bisseccao(StringFormula, x)
                resultado = F_A*F_X
                Erro = (abs(b-a)/2)
                print(f'A = {a:.5f} | B = {b:.5f} | X = {x:.5f} | F(A)*F(X) = {resultado:.5f} | ERRO: {Erro:.5f}')
                if abs(Erro) < precisao:
                    break
                elif resultado < 0:
                    b = x
                    k = k+1
                elif resultado > 0:
                    a = x
                    k = k+1
            print("------------------------------------------------")
            print(f"\nMenor raiz -> X{k}: {x}")
    elif opcao_menu == 2:
        Resolucao_Ex2()
        opcao_menu1 = int(input("Digite a opção desejada: "))
        if opcao_menu1 == 1:
            StringFormula = '1-(1+t+((t**2)/2))*e**-t-0.1'
            print(f'\nF(t) = {StringFormula}')
            List_X = []
            Valor_de_X_Funcao = []
            List_X.append(0)
            List_X.append(3)
            precisao = 0.00001
            Valor_de_X_Funcao.append(Funcao_Principal(StringFormula, List_X[0]))
            Valor_de_X_Funcao.append(Funcao_Principal(StringFormula, List_X[1]))
            print("\n-------------------")
            print("Metodo da Secante")
            print("-------------------")
            print("\n------------- Tabela de Iterações --------------------")
            print(f'X0 = {List_X[0]:.15f} | F(X0) = {Valor_de_X_Funcao[0]:.15f}')
            print(f'X1 = {List_X[1]:.15f} | F(X1) = {Valor_de_X_Funcao[1]:.15f}')
            k = 2
            while(1):
                Novo_X = metodo_secante(StringFormula, List_X[k-1], List_X[k-2])
                List_X.append(Novo_X)
                Resultado_Funcao_X = Funcao_Principal(StringFormula, Novo_X)
                Valor_de_X_Funcao.append(Resultado_Funcao_X)
                print(f'X{k} = {Novo_X:.15f} | F(X{k}) = {Resultado_Funcao_X:.15f}')
                if abs(Resultado_Funcao_X) < precisao:
                    break
                else:
                    k = k+1
            print("------------------------------------------------")
            print(f"\nMenor raiz -> X{k} = {Novo_X}")
            resultado1 = Novo_X
            List_X.clear()
            Valor_de_X_Funcao.clear()
            StringFormula = '1-(1+t+((t**2)/2))*e**-t-0.9'
            print(f'\nF(t) = {StringFormula}')
            List_X = []
            Valor_de_X_Funcao = []
            List_X.append(5)
            List_X.append(5.5)
            precisao = 0.00001
            Valor_de_X_Funcao.append(Funcao_Principal(StringFormula, List_X[0]))
            Valor_de_X_Funcao.append(Funcao_Principal(StringFormula, List_X[1]))
            print("\n-------------------")
            print("Metodo da Secante")
            print("-------------------")
            print("\n------------- Tabela de Iterações --------------------")
            print(f'X0 = {List_X[0]:.15f} | F(X0) = {Valor_de_X_Funcao[0]:.15f}')
            print(f'X1 = {List_X[1]:.15f} | F(X1) = {Valor_de_X_Funcao[1]:.15f}')
            k = 2
            while(1):
                Novo_X = metodo_secante(StringFormula, List_X[k-1], List_X[k-2])
                List_X.append(Novo_X)
                Resultado_Funcao_X = Funcao_Principal(StringFormula, Novo_X)
                Valor_de_X_Funcao.append(Resultado_Funcao_X)
                print(f'X{k} = {Novo_X:.15f} | F(X{k}) = {Resultado_Funcao_X:.15f}')
                if abs(Resultado_Funcao_X) < precisao:
                    break
                else:
                    k = k+1
            print("------------------------------------------------")
            print(f"\nMenor raiz -> X{k} = {Novo_X}")
            resultado2 = Novo_X
            print(f'\nTempo de subida = {resultado2-resultado1}')
            List_X.clear()
            Valor_de_X_Funcao.clear()
        elif opcao_menu1 == 2:
            StringFormula = '1-(1+t+((t**2)/2))*e**-t-0.1'
            a = 0
            b = 3
            precisao = 0.00001
            print(f'\nF(t) = {StringFormula}')
            print("\n-------------------")
            print("Metodo da Bissecção")
            print("-------------------")
            print("\n------------- Tabela de Iterações --------------------")
            k = 0
            while(1):
                x = metodo_da_bisseccao(a, b)
                F_A = funcao_principal_bisseccao(StringFormula, a)
                F_X = funcao_principal_bisseccao(StringFormula, x)
                resultado = F_A*F_X
                Erro = (abs(b-a)/2)
                print(f'A = {a:.5f} | B = {b:.5f} | X = {x:.5f} | F(A)*F(X) = {resultado:.5f} | ERRO: {Erro:.5f}')
                if abs(Erro) < precisao:
                    break
                elif resultado < 0:
                    b = x
                    k = k+1
                elif resultado > 0:
                    a = x
                    k = k+1
            print("------------------------------------------------")
            print(f"\nMenor raiz -> X{k}: {x}")
            resultado1 = x
            StringFormula = '1-(1+t+((t**2)/2))*e**-t-0.9'
            a = 5
            b = 5.5
            precisao = 0.00001
            print(f'\nF(t) = {StringFormula}')
            print("\n-------------------")
            print("Metodo da Bissecção")
            print("-------------------")
            print("\n------------- Tabela de Iterações --------------------")
            k = 0
            while(1):
                x = metodo_da_bisseccao(a, b)
                F_A = funcao_principal_bisseccao(StringFormula, a)
                F_X = funcao_principal_bisseccao(StringFormula, x)
                resultado = F_A*F_X
                Erro = (abs(b-a)/2)
                print(f'A = {a:.5f} | B = {b:.5f} | X = {x:.5f} | F(A)*F(X) = {resultado:.5f} | ERRO: {Erro:.5f}')
                if abs(Erro) < precisao:
                    break
                elif resultado < 0:
                    b = x
                    k = k+1
                elif resultado > 0:
                    a = x
                    k = k+1
            print("------------------------------------------------")
            print(f"\nMenor raiz -> X{k}: {x}")
            resultado2 = x
            print(f'\nTempo de subida = {resultado2-resultado1}')
    elif opcao_menu == 9:
        print("\n-----------------------------------")
        print("Programa encerrado! Até breve!")
        print("-----------------------------------\n")
        fim = True


