import speech_recognition as sr


def reconhecimento_de_voz():
    # Inicializando o reconhecedor de fala
    r = sr.Recognizer()

    # Criando o microfone
    mic = sr.Microphone()

    # Faça com que o usuário ajuste o nível de ruído ambiental
    with mic as source:
        r.adjust_for_ambient_noise(source)
        print("Diga algo em português:")
        audio = r.listen(source)
        print("Reconhecendo...")

    # Realizando o reconhecimento de fala
    try:
        #print("Você disse: " + r.recognize_google(audio, language='pt-BR'))
        return r.recognize_google(audio, language='pt-BR')
    except sr.UnknownValueError:
        print("Não foi possível entender o que você disse")
        return False
    except sr.RequestError as e:
        print("Erro ao chamar o serviço de reconhecimento de fala; {0}".format(e))
        return False