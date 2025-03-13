variaveis = []

def valida_equacoes(equacoes):
    global variaveis
    for i in range(len(equacoes)):
        equal = 0
        for j in range(len(equacoes[i])):
            if equacoes[i][j].isalpha(): # Condicional que checa se o caractere em específico é uma letra
                if equal == 1:
                    return False
                if j < len(equacoes[i]) - 1: # Se não chegou no último caractere a ser checado
                    if equacoes[i][j+1].isalpha(): # Checa se o próximo caractere também é uma letra
                        return False # Se for, retorna False
            elif not equacoes[i][j].isdigit(): # Caso contrário, checa se é um dos simbolos permitidos
                    if equacoes[i][j] != '+' and equacoes[i][j] != '-' and equacoes[i][j] != '*': #Condicional que checa se está dentro dos caracteres especiais permitidos
                        if equacoes[i][j] == '=':
                            if equal == 0:
                                equal += 1
                            else:
                                return False
                        else:
                            return False

    if equal == 1:
        return True

def monta_tabela(equacoes):
    if valida_equacoes(equacoes): #Se as equações forem corretas
        tabela = []
        vetor_temp = []
        vetor_equacoes = []
        variaveis = []
        temp = 0
        
        # Quebra as equações em vetores (Melhor para controle da equação)
        for i in range(len(equacoes)):
            vetor_temp = []
            j = 0
            while j < len(equacoes[i]):
                if equacoes[i][j].isdigit():
                    temp = int(equacoes[i][j])
                    j += 1
                    while j <= len(equacoes[i]) - 1 and equacoes[i][j].isdigit() :
                        temp = temp * 10 + int(equacoes[i][j])
                        j += 1
                    
                elif equacoes[i][j].isalpha():
                    temp = equacoes[i][j]
                    j +=1
                    while j <= len(equacoes[i]) - 1 and equacoes[i][j].isdigit() :
                        temp = temp +  equacoes[i][j]
                        j+=1
                
                else:
                    temp = equacoes[i][j]
                    j+=1
                vetor_temp.append(temp)
            vetor_equacoes.append(vetor_temp)
        #Transfere todas as constantes para o lado direito da igualdade

        for i in range(len(vetor_equacoes)):
            tem_equal = 0
            j = 0
            while j < len(vetor_equacoes[i]):
                if vetor_equacoes[i][j] == '=':
                    tem_equal = True
                if j < len(vetor_equacoes[i]) - 1:
                    if isinstance(vetor_equacoes[i][j], int) and isinstance(vetor_equacoes[i][j+1], str) and (not vetor_equacoes[i][j+1][0].isalpha()) and not tem_equal:
                        if j > 0:
                            vetor_equacoes[i].append(vetor_equacoes[i][j-1])
                            vetor_equacoes[i].pop(j-1)
                            vetor_equacoes[i].append(vetor_equacoes[i][j-1])
                            vetor_equacoes[i].pop(j-1)
                        else:
                            vetor_equacoes[i].append(vetor_equacoes[i][j])
                            vetor_equacoes[i].pop(j)
                j+=1
        #Adiciona as variáveis em um vetor para controlar a mesmas
        for i in range(len(vetor_equacoes)):
            j = 0
            for j in range(len(vetor_equacoes[i])):
                if isinstance(vetor_equacoes[i][j], str) and vetor_equacoes[i][j][0].isalpha():
                    if not vetor_equacoes[i][j] in variaveis:
                        variaveis.append(vetor_equacoes[i][j])
        
        #Checa se a quantidade de variáveis distintas é igual à quantidade de equações
        if len(variaveis) != len(equacoes):
            return False #Retorna falso pois o input não é válido

        #Ordena as equações para manter todas elas no mesmo padrão

        #Padroniza a primeira linha para usar a mesma como exemplo
        exist = False
        for i in range(len(variaveis)):
            exist = False
            for j in range(len(vetor_equacoes[0])):
                if isinstance(vetor_equacoes[0][j], str) and vetor_equacoes[0][j][0].isalpha():
                    if variaveis[i] == vetor_equacoes[0][j]:
                        exist = True
            if not exist:
                vetor_equacoes[0].insert(len(vetor_equacoes[0]) - 2, 0)
                vetor_equacoes[0].insert(len(vetor_equacoes[0]) - 2, variaveis[i])

        #Padroniza o restante se baseando na primeira linha

        for i in range(1, len(vetor_equacoes)):
            for j in range(len(variaveis)):
                exist = False
                k = 0
                qnt_variaveis = 0
                while k < len(vetor_equacoes[i]):
                    if isinstance(vetor_equacoes[i][k], str) and vetor_equacoes[i][k][0].isalpha():
                        
                        qnt_variaveis += 1
                        if vetor_equacoes[i][k] == variaveis[j]:
                            exist = True
                            if qnt_variaveis == j + 1:
                                k+=1
                                continue
                            else:
                                guarda_valores_temp = []
                                if qnt_variaveis < j + 1:
                                    if vetor_equacoes[i][k+1] == '=':
                                        k+=1
                                        continue
                                    while not k < 0 and (isinstance(vetor_equacoes[i][k], str) and vetor_equacoes[i][k][0].isalpha()):
                                        guarda_valores_temp.append(vetor_equacoes[i][k])
                                        vetor_equacoes[i].pop(k)
                                        k -= 1
                                    if j < len(variaveis) - 1: # Se não é a última variável
                                        temp = k
                                        while vetor_equacoes[i][temp] != '=' and  vetor_equacoes[i][temp] != variaveis[j-1] :
                                            temp+=1
                                        if vetor_equacoes[i][temp] == variaveis[j-1]:
                                            temp += 1
                                    else: # Se é a última variável
                                        temp = len(vetor_equacoes[i]) - 2
                                    for item in range(len(guarda_valores_temp) - 1, -1, -1):
                                        vetor_equacoes[i].insert(temp, guarda_valores_temp[item])

                                elif qnt_variaveis > j + 1:
                                    while not k < 0 and (isinstance(vetor_equacoes[i][k], str) and vetor_equacoes[i][k][0].isalpha()):
                                        guarda_valores_temp.append(vetor_equacoes[i][k])
                                        vetor_equacoes[i].pop(k)
                                        k -= 1
                                    if j == 0:
                                        temp = 0
                                    else:
                                        temp = k
                                        while temp >= 0 and vetor_equacoes[i][temp] != variaveis[j-1]:
                                            temp-=1
                                        temp += 1
                                        for item in range(len(guarda_valores_temp) - 1, -1, -1):
                                            vetor_equacoes[i].insert(temp, guarda_valores_temp[item])
                            break            
                    k+=1
                if not exist:
                    if j == 0:
                        vetor_equacoes[i].insert(0, variaveis[j])
                        vetor_equacoes[i].insert(0, 0)
                    else:
                        k = 0
                        while vetor_equacoes[i][k] != '=' and vetor_equacoes[i][k] != variaveis[j-1]:
                            k+=1
                        if vetor_equacoes[i][k] == variaveis[j-1]:
                            k+=1
                        vetor_equacoes[i].insert(k, variaveis[j])
                        vetor_equacoes[i].insert(k, 0)

        # Realiza a etapa final. Transformando na tabela somente com números para que os cálculos sejam realizados
        vetor_temp = []
        for i in range(len(vetor_equacoes)):
            vetor_temp = []
            j = 0
            if isinstance(vetor_equacoes[i][j], str) and vetor_equacoes[i][j][0].isalpha():
                vetor_temp.append(1)
                j+=1
            tem_equal = False
            equal = 0
            while j < len(vetor_equacoes[i]):
                if vetor_equacoes[i][j] == '=':
                    tem_equal = True
                else:
                    operation = False
                    if vetor_equacoes[i][j] == '-':
                        if isinstance(vetor_equacoes[i][j+1],int):
                            vetor_temp.append(vetor_equacoes[i][j+1] * -1)
                        else:
                            vetor_temp.append(-1)
                        operation = True
                        j+=1
                    elif vetor_equacoes[i][j] == '+':
                        if isinstance(vetor_equacoes[i][j+1],int):
                            vetor_temp.append(vetor_equacoes[i][j+1])
                        else:
                            vetor_temp.append(1)
                        operation = True
                        j+=1
                    elif isinstance(vetor_equacoes[i][j], int):
                        vetor_temp.append(vetor_equacoes[i][j])
                        operation = True

                    if operation and tem_equal:
                        equal += 1
                j+=1
            if equal > 1:
                for soma in range(equal - 1):
                    vetor_temp[len(vetor_temp) - equal] = vetor_temp[len(vetor_temp) - equal] + vetor_temp[len(vetor_temp) - soma - 1]
                    vetor_temp.pop(len(vetor_temp) - soma - 1)
            tabela.append(vetor_temp)
        
        return [tabela, variaveis]
    else:
        return False
