from datetime import datetime

import nonebot
import pytz
from aiocqhttp.exceptions import Error as CQHttpError
import json
import requests
from bs4 import BeautifulSoup

def judge(years):
    if years % 4 == 0 and years % 100 != 0:
        return True
    else:
        return False


def change(date, hour, minute):
    min = date.minute
    hr = date.hour
    day = date.day
    month = date.month
    year = date.year
    min += minute
    if min >= 60:
        min -= 60
        hr += 1
    hr += hour
    if hr >= 24:
        hr -= 1
        day += 1
    if day == 30 and month == 2 and judge(year):  # 判断是否为闰年
        month += 1
        day -= 29
    elif day == 29 and month == 2 and judge(year) == False:
        day -= 28
        month += 1
    elif day == 31 and month in (4, 6, 9, 11):
        day -= 30
        month += 1
    elif day == 32:
        day -= 31
        month += 1
    if month > 12:
        month = 1
        year += 1
    if min < 10:
        time = ("%s-%s-%s %s:0%s") % (year, month, day, hr, min)
        return time

    time = ("%s-%s-%s %s:%s") % (year, month, day, hr, min)
    return time

def getNiuKe():
    url = 'https://ac.nowcoder.com/acm/contest/vip-index?topCategoryFilter=13'
    html = requests.get(url)
    if html.status_code != 200:
        return
    else:
        soup = BeautifulSoup(html.text, "html.parser")
        data = {}
        data1 = {}

        div = soup.find("div", class_="nk-main with-banner-page clearfix js-container")
        div_content = div.find("div", class_="nk-content")
        div_contest = div_content.find("div", class_="platform-mod js-current")
        for contest in div_contest.find_all("div", class_="platform-item js-item"):
            next = contest.find("div", class_="platform-item-cont")
            a = next.find("a")
            li = next.find('li', class_='match-time-icon')
            link = a['href']
            name = a.string
            if "小白" in name or "练习赛" in name or "周周" in name or "挑战赛" in name:
                data[name] = li.string
                data1[name] = "https://ac.nowcoder.com" + link
        name = list(data)
        f = 0
        for it in name:
            time = data[it][:21]
            time = time[5:]
            data[it] = time

        fp = open("niuke.json", 'w', encoding='utf-8')
        item_json = json.dumps(data, ensure_ascii=False)
        fp.write(item_json)
        fp.close()
        fp1 = open("niuke_link.json", 'w', encoding='utf-8')
        item_json = json.dumps(data1, ensure_ascii=False)
        fp1.write(item_json)
        fp1.close()


def getCodeChef():
    url = 'https://www.codechef.com/contests'
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0)Gecko/20100101 Firefox/66.0"
    }
    r = requests.get(url, timeout=30, headers=headers)
    if (r.status_code != 200):  # 由于codechef网站访问比较慢当出错的时候就在进行访问一次
        r = requests.get(url, timeout=30, headers=headers)

    soup = BeautifulSoup(r.text, "html.parser")
    table = soup.find_all("table", class_="dataTable")
    table = table[1]
    tbody = table.find("tbody")
    name = []
    time = []
    link = []

    data_time = tbody.find_all("td", class_="start_date")
    for it in tbody.find_all('td'):
        # print(it)

        a = it.find("a")

        if a is not None:
            name.append(a.string)
            print(a['href'])
            link.append("https://www.codechef.com" + a['href'])

    for it in data_time:
        time.append(it.text)

    for i in range(0, len(time)):
        date = datetime.strptime(time[i], '%d %b %Y  %H:%M:%S')
        time[i] = change(date, hour=2, minute=30)  # 印度与中国时间相差2时30分
    # 创建字典 比赛名称-->时间

    data = {}
    data1 = {}

    for i in range(0, len(time)):
        data[name[i]] = time[i]
        data1[name[i]] = link[i]

    # 将获取的字典信息 导入json  不建议用数据库 因为信息比较少用json文件方便
    fp = open("codechef.json", 'w', encoding='utf-8')
    fp1 = open("codechef_link.json", 'w', encoding='utf-8')
    item_json = json.dumps(data, ensure_ascii=False)
    fp.write(item_json)
    item_json = json.dumps(data1, ensure_ascii=False)
    fp1.write(item_json)
    fp.close()
    fp1.close()

def getAtcoder():
    url = 'https://atcoder.jp/'
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0)Gecko/20100101 Firefox/66.0"
    }
    r = requests.get(url, timeout=30, headers=headers)

    soup = BeautifulSoup(r.text, "html.parser")
    div = soup.find("div", id="contest-table-upcoming")

    if div is None:

        print("最近没有比赛")
        data = {"最近没有比赛" : "......"}
        fp = open("atcoder.json", 'w', encoding='utf-8')
        item_json = json.dumps(data, ensure_ascii=False)
        fp.write(item_json)
        fp.close()


    else:
        name = []
        time = []
        link = []
        tbody = div.find("tbody")
        for it in tbody.find_all("tr"):
            a = it.find_all("a")
            print(a[1]['href'])
            link.append("https://atcoder.jp" + a[1]['href'])
            time.append(a[0].string)
            name.append(a[1].string)


        data = {}
        data1 = {}
        for i in range(0, len(name)):
            ti = time[i][:-8]
            date = datetime.strptime(ti, '%Y-%m-%d %H:%M')
           # print(date)
            #print(name[i])
            data[name[i]] = change(date=date, hour=-1, minute=0)  # 日本时差1小时
            #print(change(date=date, hour=-1, minute=0))
            data1[name[i]] = link[i]
       # print(data)
        fp = open("atcoder.json", 'w', encoding='utf-8')
        fp1 = open("atcoder_link.json", 'w', encoding='utf-8')
        item_json = json.dumps(data, ensure_ascii=False)
        fp.write(item_json)
        item_json = json.dumps(data1, ensure_ascii=False)
        fp1.write(item_json)
        fp.close()
        fp1.close()


def getFirstNiukeLink():
    file = open('niuke_link.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    name = list(data)
    return data[name[0]]


def getFirstCodeChefLink():
    file = open('codechef_link.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    name = list(data)
    return data[name[0]]

def getFirstAtcoderLink():
    file = open('atcoder_link.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    name = list(data)
    return data[name[0]]

def getAtcoderMsgLink():
    file = open('atcoder_link.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    file.close()
    return data

def getCodeChefMsgLink():
    file = open('codechef_link.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    file.close()
    return data

def getCodeforcesMsgLink():
    file = open('cf.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    name = list(data)
    for it in name:
        data[name] = 'https://codeforces.com/contests'
    return data

def getNiuKeMsgLink():
    file = open('niuke_link.json', 'r', encoding='utf-8')
    js = file.read()
    data = json.loads(js)
    file.close()
    return data

sql ='INSERT into cf_msg  VALUES(\" %s \", \" %s \") on DUPLICATE key UPDATE cf_id = \" %s \", msg = \" %s \";'%("zhaobo", "1", "2", "2")
print(sql)