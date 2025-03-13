from tkinter import *


def Resultado():
    # RECEBE O VALOR INSERINDO PELO USUARIO - NOTA A
    valor_notaA = float(nota_a.get())
    # RECEBE O VALOR INSERINDO PELO USUARIO - NOTA B
    valor_notaB = float(nota_b.get())
    # RECEBE O VALOR INSERINDO PELO USUARIO - NOTA C
    valor_notaC = float(nota_c.get())
    # RELIZA O CALCULO DA MÉDIA
    media = float((valor_notaA+valor_notaB+valor_notaC)/3)
    media_formatada = "{:.1f}".format(media)  # MEDIA COM ÚNICA CASA DECIMAL
    if media >= 6:
        Label(app, text=str(media_formatada), background='#fff', foreground="#009",
              anchor=W).place(x=195, y=180, width=90, height=20)  # APRESENTAR MÉDIA NA JANELA
        Label(app, text='APROVADO!', background='#fff', foreground="#009",
              anchor=W).place(x=195, y=210, width=90, height=20)  # APRESENTAR APROVAÇÃO
    else:
        Label(app, text=str(media_formatada), background='#fff', foreground="#ff0000",
              anchor=W).place(x=195, y=180, width=90, height=20)  # APRESENTAR MÉDIA NA JANELA
        Label(app, text='REPROVADO!', background='#fff', foreground="#ff0000",
              anchor=W).place(x=195, y=210, width=90, height=20)  # APRESENTAR REPROVAÇÃO


# INICIANDO TK
app = Tk()

# DEFININDO O NOME DA JANELA
app.title("Calculadora de Notas")

# DEFININDO O TAMANHO DA JANELA
app.geometry("500x300")

# DEFININDO A COR DE FUNDO
app.configure(background='#1d6869')

# TEXTO - EXIBIDO NA TELA
Label(app, text='Nome:', background='#fff', foreground="#000000",
      anchor=W).place(x=10, y=10, width=50, height=20)

# CAIXA DE TEXTO - INSERIR TEXTO
nome_aluno = Entry(app)
nome_aluno.place(x=10, y=40, width=400, height=20)

# TEXTO - EXIBIDO NA TELA
Label(app, text='Nota A', background='#fff', foreground="#000000",
      anchor=W).place(x=10, y=80, width=50, height=20)

# CAIXA DE TEXTO - INSERIR NOTA A
nota_a = Entry(app)
nota_a.place(x=10, y=110, width=50, height=20)

Label(app, text='Nota B', background='#fff', foreground="#000000",
      anchor=W).place(x=80, y=80, width=50, height=20)

# CAIXA DE TEXTO - INSERIR NOTA B
nota_b = Entry(app)
nota_b.place(x=80, y=110, width=50, height=20)

# TEXTO - EXIBIDO NA TELA
Label(app, text='Nota C', background='#fff', foreground="#000000",
      anchor=W).place(x=150, y=80, width=50, height=20)

# CAIXA DE TEXTO - INSERIR NOTA C
nota_c = Entry(app)
nota_c.place(x=150, y=110, width=50, height=20)

# BUTTON CALCULAR - COMMAND CHAMA A FUNÇÃO RESULTADO PARA OS CALCULOS NECESSARIOS
Button(app, text="Realizar o Cálculo!", command=Resultado).place(
    x=190, y=150, width=100, height=20)

app.mainloop()
