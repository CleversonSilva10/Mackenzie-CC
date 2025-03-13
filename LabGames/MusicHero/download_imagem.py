import urllib.request as request
import shutil
import os

DIRETORIO_IMG_DOWNLOADS = 'Midia/IMAGENS/IMAGENS_DOWNLOAD/'

def download_img(link_img, banda):
    url = link_img
    try:
        request.urlretrieve(url, DIRETORIO_IMG_DOWNLOADS+banda+'.png')
        return DIRETORIO_IMG_DOWNLOADS+banda+'.png'
    except Exception as ex:
        print(ex)

def excluir():
    for arquivos in os.listdir(DIRETORIO_IMG_DOWNLOADS):
        caminho_arquivo = os.path.join(DIRETORIO_IMG_DOWNLOADS, arquivos)
        try:
            if os.path.isfile(caminho_arquivo) or os.path.islink(caminho_arquivo):
                os.unlink(caminho_arquivo)
        except Exception as e:
            print('Failed to delete %s. Reason: %s' % (caminho_arquivo, e))
