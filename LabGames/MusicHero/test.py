import pygame as pg
from settings import *


# Inicializar o Pygame
pg.init()

def mostrar_img_top10(screen):
    plano_de_fundo = pg.image.load(BACKGROUND_MENU_TOP_10)
    scaled_image = pg.transform.scale(plano_de_fundo, (1280, 720))
    screen.blit(scaled_image, (0,0))     
    lista_imagens = [teste1, teste2, teste3, teste4, teste5, teste6, teste7, teste8, teste9, teste10]
    y_left = 136
    y_rigth = 136
    for i in range(0, 5):
        image_left = pg.image.load(lista_imagens[i])            
        scaled_image = pg.transform.scale(image_left, (78, 79))
        screen.blit(scaled_image, (93, y_left))
        y_left+= 103
    for i in range(5, 10):
        image_right = pg.image.load(lista_imagens[i])            
        scaled_image = pg.transform.scale(image_right, (78, 79))
        screen.blit(scaled_image, (705, y_rigth))
        y_rigth+=103       


# Configurar a tela
screen = pg.display.set_mode((1280, 720))

# Carregar a fonte
font = pg.font.Font(None, 36)

# Renderizar o texto como uma imagem
text = "Texto com caracteres especiais: #, é, í, ó, ú"
text_image = font.render(text, True, (255, 0, 0))

# Loop do jogo
running = True
while running:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False
        mostrar_img_top10(screen)
    # Atualizar a tela
    pg.display.update()

# Finalizar o Pygame
pg.quit()
