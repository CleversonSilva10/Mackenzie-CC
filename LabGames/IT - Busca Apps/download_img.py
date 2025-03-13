import urllib.request as request

def download_img(html, nome_app, posicao):
    DIRETORIO_IMG_DOWNLOADS = 'img_apps_playstore/'
    img_app = html.find('div', attrs={'class' : 'Mqg6jb Mhrnjf'}).find('img')['src']    
    nome_app = nome_app.replace(' ', '_')
    url = img_app
    print(url)
    try:
        request.urlretrieve(url, DIRETORIO_IMG_DOWNLOADS+str(posicao)+'_'+nome_app+'.png')
    except Exception as ex:
        print(ex)
        print(f'IMG APP: {nome_app}.png não foi realizada com sucesso!')