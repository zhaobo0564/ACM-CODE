from nonebot import on_command, CommandSession
from bs4 import BeautifulSoup
import requests
from datetime import datetime
import json
import random
 
def getSorce(name):
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0)Gecko/20100101 Firefox/66.0"
    }

    url = "https://codeforces.com/profile/%s" % (name)
    r = requests.get(url, timeout=30, headers=headers)
    if r.url != url:
        return [1]
    if r.status_code != 200:
        return []
    html = r.text
    soup = BeautifulSoup(html, "html.parser")
    div = soup.find("div", class_="info")
    ul = div.find("ul")
    li = ul.find('li')
    span = li.find_all("span")
    # print(span)
    sorce = []
    for it in span:
        sorce.append(it.string)
    data = []
    data.append(sorce[0])
    data.append(sorce[-1])
    return data

def getCfSelfMsg(name):
    url = "https://codeforces.com/contests/with/%s" % (name)
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0)Gecko/20100101 Firefox/66.0"
    }

    r = requests.get(url, timeout=30, headers=headers)
    if r.url != url:
        text ="找不到 "+name+" [CQ:face,id=15][CQ:face,id=15]]"
        return text
    if r.status_code != 200:
        return "cf官网无法访问[CQ:face,id=15][CQ:face,id=15]"
    print("Yes")
    html = r.text
    soup = BeautifulSoup(html, "html.parser")
    div = soup.find("div", class_="datatable")
    tbody = div.find("tbody")
    div1 = 0
    div2 = 0
    div3 = 0
    other = 0
    contestNum = 0
    div1_ranks = 0
    div2_ranks = 0
    div3_ranks = 0
    other_ranks = 0
    div1_prombles = 0
    div2_prombles = 0
    div3_prombles = 0
    other_prombles = 0
    rating = 0
    max = 1000000
    f = 1
    
    for it in tbody.find_all("tr"):
        td = it('td')
        contestName = td[1]('a')[0].string
        

        if("Div. 2" in contestName):
            div2_ranks += int(td[2].text, 10)
            div2_prombles += int(td[3].text, 10)
            div2 += 1
        elif("Div. 1" in contestName):
            div1_ranks += int(td[2].text, 10)
            div1_prombles += int(td[3].text, 10)  
            div1 += 1  
        elif("Div. 3" in contestName):
            div3_ranks += int(td[2].text, 10)
            div3_prombles += int(td[3].text, 10)
            div3 += 1
        else:
            other_ranks += int(td[2].text, 10)
            other_prombles += int(td[3].text, 10)
            other += 1
        
        rating += int(td[4].text, 10)
        if f == 1:
            contestNum = int(td[0].string, 10)
            f = 0

        
    if contestNum == 0:
        text = name + " 还没有打过cf呢[CQ:face,id=15][CQ:face,id=15]"
        return text

    sorce = getSorce(name)
    print(contestNum)
    text = "cf 名称：%s\r\n"%(name)
    text += "cf-raing: %s\r\n"%(sorce[0])
    text += "cf最高rating: %s\r\n"%(sorce[1])
    text += "比赛总数：%s\r\n"%(contestNum)
    text += "每场平均加分：%s\r\n\r\n"%(round(rating / contestNum, 2))


    if(div1 == 0):
        pass
        #text = "div1 : 还没有打过哦！\r\n"
    else:
        text += "div1-参加场数: %s \r\n"%(div1)
        text += "div1-均场解题数：%s\r\n"%(round(div1_prombles / div1, 2))
        text += "div1-均场排名：%s\r\n\r\n"%(round(div1_ranks / div1, 2))

    if(div2 == 0):
        pass
        #text += "div2: 还没有没打过哦！\r\n"
    else:
        text += "div2-参加场数: %s \r\n"%(div2)
        text += "div2-均场解题数：%s\r\n"%(round(div2_prombles / div2, 2))
        text += "div2-均场排名：%s\r\n\r\n"%(round(div2_ranks / div2, 2))
    if(div3 == 0):
        pass
        #text += "div3: 还没有打过哦！"
    else:
        text += "div3-参加场数: %s \r\n"%(div3)
        text += "div3-均场解题数：%s\r\n"%(round(div3_prombles / div3, 2))
        text += "div3-均场排名：%s\r\n\r\n"%(round(div3_ranks / div3, 2))
    
    if(other != 0):
        text += "global-参加场数: %s \r\n"%(other)
        text += "global-均场解题数：%s\r\n"%(round(other_prombles / other, 2))
        text += "global-均场排名：%s\r\n\r\n"%(round(other_ranks / other, 2))
    
    return text


    

  



msg = "sa s"
msg = str(msg)
print(msg.split())

name = input()
print(getCfSelfMsg(name))

    
