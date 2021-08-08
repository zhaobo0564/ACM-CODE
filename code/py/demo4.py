from nonebot import on_command, CommandSession
from bs4 import BeautifulSoup
import requests
from datetime import datetime
import json
import random
import pymysql
from requests import exceptions


def mysqlConnect(account):
    connect = pymysql.connect(**account)
    return connect

account = {
        'user': 'root',
        'password': 'zhaobo123..',
        'host': '193.112.141.129',
        'database': 'cf'
    }
connect = mysqlConnect(account)
cursor = connect.cursor(cursor=pymysql.cursors.DictCursor)



def getSorce(name):
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0)Gecko/20100101 Firefox/66.0"
    }

    url = "https://codeforces.com/profile/%s" % (name)
    html = ""
    try:
        r = requests.get(url, timeout=3, headers=headers)
        r.raise_for_status()   
        if r.url != url:
            return [1]
        html = r.text
    except exceptions.Timeout as e:
        print("超时！")
        return [2]
    except requests.HTTPError:
        print('http状态码非200')
        return [3]

    
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
    html = ""
    print(url)
    try:
        r = requests.get(url, timeout=3, headers=headers)
        r.raise_for_status()
        if r.url != url:
            text = "找不到 " + name + " [CQ:face,id=15][CQ:face,id=15]"
            return text
        html = r.text
    except exceptions.Timeout as e:
        return "超时"
        
    except requests.HTTPError:
        return "cf官网无法访问"
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
        if(max > int(td[2].text, 10)):
            max = int(td[2].text, 10)

        if ("Div. 2" in contestName):
            div2_ranks += int(td[2].text, 10)
            div2_prombles += int(td[3].text, 10)
            div2 += 1
        elif ("Div. 1" in contestName):
            div1_ranks += int(td[2].text, 10)
            div1_prombles += int(td[3].text, 10)
            div1 += 1
        elif ("Div. 3" in contestName):
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
        text = name + " 还没有打过比赛呢[CQ:face,id=15][CQ:face,id=15]"
        return text


    sorce = getSorce(name)
    if sorce[0] == 2:
        return "超时"
    elif sorce[0] == 3:
        return "cf官网无法访问"
    text = "cf-ID：%s\r\n" % (name)
    text += "cf-rating: %s\r\n" % (sorce[0])
    text += "cf最高rating: %s\r\n" % (sorce[1])
    text +="cf最高排名：%s\r\n"%(max)
    text += "比赛总数：%s\r\n" % (contestNum)
    text += "每场平均加分：%s\r\n\r\n" % (round(rating / contestNum, 2))
    #print(text)

    if (div1 == 0):
        pass
        # text = "div1 : 还没有打过哦！\r\n"
    else:
        text += "div1-参加场数: %s \r\n" % (div1)
        text += "div1-均场解题数：%s\r\n" % (round(div1_prombles / div1, 2))
        text += "div1-均场排名：%s\r\n\r\n" % (round(div1_ranks / div1, 2))

    if (div2 == 0):
        pass
        # text += "div2: 还没有没打过哦！\r\n"
    else:
        text += "div2-参加场数: %s \r\n" % (div2)
        text += "div2-均场解题数：%s\r\n" % (round(div2_prombles / div2, 2))
        text += "div2-均场排名：%s\r\n\r\n" % (round(div2_ranks / div2, 2))
    if (div3 == 0):
        pass
        # text += "div3: 还没有打过哦！"
    else:

        text += "div3-参加场数: %s \r\n" % (div3)
        text += "div3-均场解题数：%s\r\n" % (round(div3_prombles / div3, 2))
        text += "div3-均场排名：%s\r\n\r\n" % (round(div3_ranks / div3, 2))

    if (other != 0):
        text += "global-参加场数: %s \r\n" % (other)
        text += "global-均场解题数：%s\r\n" % (round(other_prombles / other, 2))
        text += "global-均场排名：%s\r\n\r\n" % (round(other_ranks / other, 2))

    text +="(div3蓝名以上的时候打的比赛不算在内)"
    #print(text)
    return text

def insertMsg(name, msg):
    try:
        sql = 'INSERT into codeforces  VALUES(\"%s\", \"%s\") on DUPLICATE key UPDATE cf_name = \"%s\", msg = \"%s\";' % (
        name, msg, name, msg)
        #print(sql)
        cursor.execute(sql)
        connect.commit()
       # print("****")
    except:

        print("写入错误")

def getMsg(name, text):
    sql = "select * from codeforces;"
    cursor.execute(sql)
    row = cursor.fetchall()
    for it in row:
        name .append(it['cf_name'])
        text.append(it['msg'])



def updateMsg():
    name = []
    text = []
    getMsg(name, text)
    print(text)
    for i in range(0, len(name)):
        name[i] = name[i].split()[0]
        ans = getCfSelfMsg(name[i])
        if "超时" in ans  or "无法访问" in ans:
            continue
        text[i] = ans
    print("*"*10)
    print(text)
    for i in range(0, len(name)):
        insertMsg(name[i], text[i])

def getMysqlMsg(name):
    sql = 'select * from codeforces where cf_name =' +'\''  + name +'\';'
    print(sql)
    cursor.execute(sql)
    row = cursor.fetchone()
    return row


now = datetime.now()

print(now.minute)


  




