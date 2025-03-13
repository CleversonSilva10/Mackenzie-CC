import pygame as pg

# Inicializar o Pygame
pg.init()

# Criar uma janela
screen = pg.display.set_mode((800, 600))

# Loop de eventos
running = True
while running:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False
        if event.type == pg.MOUSEBUTTONDOWN:
            if event.button == 1:
                print("Botão esquerdo pressionado na posição", event.pos)
            elif event.button == 2:
                print("Botão do meio pressionado na posição", event.pos)
            elif event.button == 3:
                print("Botão direito pressionado na posição", event.pos)

# Finalizar o Pygame
pg.quit()
