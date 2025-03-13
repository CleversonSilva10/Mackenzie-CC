import cv2
import mediapipe as mp

camera = cv2.VideoCapture(0) #Relizar captura da webcam


def reconhecimento_maos(video):
  hand = mp.solutions.hands #Responsável pelas config do mediapipe
  Hand = hand.Hands(max_num_hands = 1) #Número maximo de mãos para reconhecer
  mpDraw = mp.solutions.drawing_utils #Isso é responsável por desenhar as linhas na mão
  while True:
    check, img = video.read()
    img = cv2.resize(img, (800, 640))
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    #img = cv2.rotate(img, cv2.ROTATE_90_COUNTERCLOCKWISE)    
    results = Hand.process(imgRGB)
    handsPoints = results.multi_hand_landmarks
    h, w, _ = img.shape
    pontos = []
    if handsPoints:
      for points in handsPoints:
        #print(points)
        mpDraw.draw_landmarks(img, points, hand.HAND_CONNECTIONS)
        for id, cord in enumerate(points.landmark):
          cx, cy = int(cord.x*w), int(cord.y*h)
          #cv2.putText(img, str(id), (cx, cy), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
          pontos.append((cx, cy))
      contador = 0
      dedos = [8, 12, 16, 20]
      if points:
        if pontos[4][0] < pontos[2][0]:
          contador +=1
        for x in dedos:          
          if pontos[x][1] < pontos[x-2][1]:
            contador +=1
        return img, str(contador)
      cv2.putText(img, str(contador), (100,100), cv2.FONT_HERSHEY_SIMPLEX, 4, (255, 0 , 0), 5)
      cv2.imshow('imagem', img)
      cv2.waitKey(1)