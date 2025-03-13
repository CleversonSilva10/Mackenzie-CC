import pygame as pg
from settings import *
from pygame.locals import *
from  pyvidplayer import Video
#from comando_voz import reconhecimento_de_voz
import time
from search_tabs import buscar_partitura
from download_imagem import excluir

class Menu:
    def __init__(self):
        pg.init()
        pg.mixer.init()
        self.TAMANHO_TELA = (1280,720)
        self.x = 1280
        self.y = 720
        self.screen_tela = pg.display.set_mode(self.TAMANHO_TELA)
        self.Nome_Janela = pg.display.set_caption(NOME_DO_JOGO)
        self.Icone_Janela = pg.display.set_icon(pg.image.load(ICONE_JANELA))
        self.clock = pg.time.Clock()
        self.FPS = 60
        self.clock.tick(self.FPS)
        #__________________________________________________-
        self.text = ''
        self.digitando = []
        self.foto = ''
        self.paginas = []
        self.nome = ''
        #__________________________________________________-
        self.loading_or_restart(INTRO_COMPLETA_MP4, 'restart', 'PRESS_START')
        pass

    def press_start(self):
        self.loading_or_restart(press_start_MP4, 'restart', 'PRESS_START')

    def loading_or_restart(self, video_desejado, comando, menu_utilizado):
        if comando == 'loading':
            self.media = Video(video_desejado)
            self.media.set_size((TAMANHO_TELA))
            video_ativo = True
            while video_ativo:
                self.media.draw(self.screen_tela, (0,0), force_draw=False)
                pg.display.update()
                if self.media.active == False:
                    video_ativo = False
            self.media.close()
        
        elif comando == 'restart':
            self.media = Video(video_desejado)
            self.media.set_size((TAMANHO_TELA))
            video_ativo = True
            while video_ativo:
                self.media.draw(self.screen_tela, (0,0), force_draw=False)
                pg.display.update()
                if self.media.active == False:
                    self.media.restart()
                condicao, tecla = self.botoes_de_cada_menu(menu_utilizado)
                if condicao == True:
                    video_ativo = False
                    return tecla
                elif condicao == 'TEXTO':
                    video_ativo = True
                    return tecla

    def mostrar_img_top10(self):  
        lista_imagens = [teste1, teste2, teste3, teste4, teste5, teste6, teste7, teste8, teste9, teste10]
        y_left = 136
        y_rigth = 136
        for i in range(0, 5):
            image_left = pg.image.load(lista_imagens[i])            
            scaled_image = pg.transform.scale(image_left, (78, 79))
            self.screen_tela.blit(scaled_image, (93, y_left))
            y_left+= 103
        for i in range(5, 10):
            image_right = pg.image.load(lista_imagens[i])            
            scaled_image = pg.transform.scale(image_right, (78, 79))
            self.screen_tela.blit(scaled_image, (705, y_rigth))
            y_rigth+=103     

    def mouse(self, x_left, x_right, y_up, y_down):      
        for event in pg.event.get():
            mouse_x, mouse_y = pg.mouse.get_pos()
            print('x:', mouse_x, 'y:', mouse_y)          
            if event.type == pg.MOUSEBUTTONDOWN:
                if (event.button == 1 and mouse_x >= x_left  and mouse_x <= x_right and mouse_y >= y_up and mouse_y <= y_down):
                    toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                    play = pg.mixer.music.play()
                    self.media.close()
                    pg.display.update()
                    return 1                  

    def botoes_de_cada_menu(self, menu_atual):
        if menu_atual == 'PRESS_START':
            for event in pg.event.get():
                if event.type == pg.KEYDOWN:
                    if event.key == pg.K_RETURN:
                        toque = pg.mixer.music.load(press_start_confirmado_mp3)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 0
        elif menu_atual == 'MENU_PRINCIPAL':
            self.media.set_volume(0) # Removendo o som do menu
            for event in pg.event.get():
                mouse_x, mouse_y = pg.mouse.get_pos()             
                if event.type == pg.MOUSEBUTTONDOWN:
                    if (event.button == 1 and mouse_x >= 37 and mouse_x <= 218 and mouse_y >= 619 and mouse_y <=674):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 1
                    elif (event.button == 1 and mouse_x >= 255 and mouse_x <= 435 and mouse_y >= 619 and mouse_y <=674):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 2
                    elif (event.button == 1 and mouse_x >= 471 and mouse_x <= 667 and mouse_y >= 619 and mouse_y <=674):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 3
                    elif (event.button == 1 and mouse_x >= 704  and mouse_x <= 885 and mouse_y >= 619 and mouse_y <=674):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 4
        elif menu_atual == 'PLAYGAME':
            for event in pg.event.get():
                mouse_x, mouse_y = pg.mouse.get_pos()
                if event.type == pg.MOUSEBUTTONDOWN:
                    if (event.button == 1 and mouse_x >= 240   and mouse_x <= 422 and mouse_y >= 300  and mouse_y <=357):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 1
                    elif (event.button == 1 and mouse_x >= 240   and mouse_x <= 422 and mouse_y >= 389   and mouse_y <=447):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 2
                    elif (event.button == 1 and mouse_x >= 240   and mouse_x <= 422 and mouse_y >= 480   and mouse_y <=535):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 3          
        elif menu_atual == 'Buscar_Cifra':
            font = pg.font.Font(None, 32)
            for event in pg.event.get():
                 if event.type == pg.KEYDOWN:
                    if event.unicode.isalpha():
                        self.digitando.append(event.unicode)
                        digitando = ''.join(self.digitando)
                        text_image = font.render(digitando, True, (255, 255, 255))
                        self.screen_tela.blit(text_image, (180, 295))                    
                    
                    elif event.key == pg.K_BACKSPACE:
                        self.digitando.pop()
                        digitando = ''.join(self.digitando)
                        text_image = font.render(digitando, True, (255, 255, 255))
                        self.screen_tela.blit(text_image, (180, 295))                  
                    
                    elif event.key == pg.K_SPACE:
                        self.digitando.append(' ')
                        digitando = ''.join(self.digitando)
                        text_image = font.render(digitando, True, (255, 255, 255))
                        self.screen_tela.blit(text_image, (180, 295))                     
                    
                    elif event.key == pg.K_RETURN:
                        resposta_string = ''.join(self.digitando)
                        self.digitando.clear()
                        return 'TEXTO', resposta_string
            pg.display.update()
        elif menu_atual == 'APRESENTAR_CIFRA':
            #COLOCAR NOME DA MÚSICA E ARTISTA NA TELA
            font = pg.font.Font(None, 36)
            renderizando_texto = font.render(self.nome, True, (255, 255, 255))
            self.screen_tela.blit(renderizando_texto, (200, 50))
            renderizando_cifra = font.render(self.paginas, True, (255, 255, 255))
            self.screen_tela.blit(renderizando_cifra, (40, 140))
            
            #COLOCAR A IMAGEM NA TELA
            image = pg.image.load(self.foto)            
            scaled_image = pg.transform.scale(image, (101, 91))
            self.screen_tela.blit(scaled_image, (49, 28))
            for event in pg.event.get():
                # mouse_x, mouse_y = pg.mouse.get_pos()
                # print("Posição do mouse:", mouse_x, mouse_y)                
                if event.type == pg.KEYDOWN:
                    if event.key == pg.K_1:
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        excluir()
                        return True, 1            
        elif menu_atual == 'APRESENTAR_ACORDES':
            for event in pg.event.get():
                # mouse_x, mouse_y = pg.mouse.get_pos()
                # print('x:', mouse_x, 'y:', mouse_y)
                if event.type == pg.MOUSEBUTTONDOWN:
                    if (event.button == 1 and mouse_x >= 1194    and mouse_x <= 1247 and mouse_y >= 645 and mouse_y <=699):
                        toque = pg.mixer.music.load(SOUND_SELECT_MENU)
                        play = pg.mixer.music.play()
                        self.media.close()
                        pg.display.update()
                        return True, 1          
        elif menu_atual == 'TOP10_LIST':
            if self.mouse(192, 601, 139, 215) == 1 or self.mouse(94 , 170, 136, 213) == 1:
                return True, 1
            # if self.mouse(192, 601, 139, 215) == 1:
            #     return True, 1
            # if self.mouse(192, 601, 347 , 424) == True:
            #     return True, 1                               
        return False, -1                                                                                                                 

    def menu_principal(self):
        tecla_menu_principal = self.loading_or_restart(MENU_PRINCIPAL_MP4, 'restart', 'MENU_PRINCIPAL')
        if tecla_menu_principal == 1:
            self.play_game()
        elif tecla_menu_principal == 2:
            self.tela_afinacao()

    #OPÇÃO 1
    def play_game(self):
        tecla = self.loading_or_restart(PLAY_GAME_MP4, 'restart', 'PLAYGAME')
        if tecla == 1:
            pesquisa = self.loading_or_restart(PLAY_BUSCAR_CIFRA_DIGITAR_MP4, 'restart', 'Buscar_Cifra')
            self.foto, self.nome, self.paginas = buscar_partitura(pesquisa)
            time.sleep(2)
            self.loading_or_restart(PLAY_APRESENTAR_CIFRA_MP4, 'restart', 'APRESENTAR_CIFRA')          
        elif tecla == 2:
            self.loading_or_restart(TOP_10, 'restart', 'TOP10_LIST')
        elif tecla == 3:
            self.acordes()                
    
    def tela_afinacao(self):
        self.loading_or_restart(TELA_AFINACAO_MP4, 'restart', 'MENU_PRINCIPAL')

#APRENDER_ACORDES_
    def acordes(self):
        tecla = self.loading_or_restart(acordes_pt1, 'restart', 'APRESENTAR_ACORDES')
        if tecla == 1:
            tecla = self.loading_or_restart(acordes_pt2, 'restart', 'APRESENTAR_ACORDES')
            if tecla == 1:
                self.loading_or_restart(acordes_pt3, 'restart', 'APRESENTAR_ACORDES') 
