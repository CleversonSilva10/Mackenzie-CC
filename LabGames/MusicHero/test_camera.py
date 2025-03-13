import cv2
import pygame as pg
from comando_maos import reconhecimento_maos
from time import time

# Inicializar a câmera
camera = cv2.VideoCapture(0)

# Inicializar o Pygame
pg.init()
font = pg.font.Font(None, 36)
clock = pg.time.Clock()

# Criar uma janela do Pygame
screen = pg.display.set_mode((1280, 720))

# Loop principal
running = True
while running:
    clock.tick(60)
    for event in pg.event.get():
        # Obter o próximo frame da câmera
        frame, contagem = reconhecimento_maos(camera)

        # Converter o frame para o formato do Pygame
        frame = pg.surfarray.make_surface(frame)

        # Exibir o frame na tela
        screen.blit(frame, (0, 0))
        renderizando_texto = font.render(contagem, True, (255, 255, 255))
        screen.blit(renderizando_texto, (200, 50))
        pg.display.update()
        # Verificar eventos do Pygame
        if event.type == pg.QUIT:
            running = False
    # Finalizar a câmera e o Pygame
camera.release()
pg.quit()
