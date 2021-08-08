import requests
from bs4 import BeautifulSoup
import json


def getNiuKeSchool():
    url = 'https://ac.nowcoder.com/acm/contest/vip-index?topCategoryFilter=14'

    r = requests.get(url)

    soup = BeautifulSoup(r.text, "html.parser")

    div = soup.find_all("div", class_ ='platform-item js-item')


    name = []
    time = []
    url = []

    for it in div:
        div1 = it.find("div", class_ ='platform-item-cont')
        #print(div1)
        a = div1('a')
        i = div1('i')
        li = div1.find("li", class_='match-time-icon')

        if(len(i) > 0):
            if("加密" in i[0]['title']):
                continue
        
        name.append(a[0].string)
        url.append("https://ac.nowcoder.com" + a[0]['href'])
        time.append(li.string[5:21])

    data = {}
    data1 = {}

    for i in range(0, len(name)):
        data[name[i]] = time[i]
        data1[name[i]] = url[i]

    fp = open("niuke_school.json", 'w', encoding='utf-8')
    item_json = json.dumps(data, ensure_ascii=False)
    fp.write(item_json)
    fp.close()
    fp1 = open("niuke_link_school.json", 'w', encoding='utf-8')
    item_json = json.dumps(data1, ensure_ascii=False)
    fp1.write(item_json)
    fp1.close()


def getFirstNiukeSchoolLink():
    file = open('niuke_link_school.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    name = list(data)
    return data[name[0]]

def getFirstNiukeSchool():
    file = open('niuke_school.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    name = list(data)
    niuke = {}
    niuke[name[0]] = data[name[0]]
    return niuke