import requests
import json

def getCodeforceMsg(name):
    url = " https://codeforces.com/api/user.info?handles=" + name
    html = ""
    try:
        r = requests.get(url, timeout=3)
        html = r.text
    except:
        return "timeout!!!"

    content_json = json.loads(html)

    if content_json['status'] != "OK":
        return "找不到 " + name + " [CQ:face,id=15][CQ:face,id=15]"
    max_rating = 0
    now_rating = 0
    city = ""
    organize = ""
    result = content_json['result'][0]

    if 'rating' not in result.keys():
        return name + " 还没有打过比赛呢[CQ:face,id=15][CQ:face,id=15]"
    max_rating = result['maxRating']
    now_rating = result['rating']
    rating = result['rating']
    if 'city' in result.keys():
        city = result['city']
    if 'organization' in result.keys():
        organize = result['organization']

    #contest

    url = ' https://codeforces.com/api/user.rating?handle=' + name
    try:
       r = requests.get(url, timeout=3)
       html = r.text
    except:
        return "timeout!!!"

    const_json = json.loads(html)
    if const_json['status'] != 'OK':
        return "请求过多，请稍后在查询！"
    result = const_json['result']
    contests = len(result)
    maxs = 100000000
    rate = 0.0
    contestname = ""
    rank = ""
    score = ""
    for it in result:
        maxs = min(maxs, it['rank'])
        contestname = it['contestName']
        rank = it['rank']
        score = it['newRating'] - it['oldRating']
    text = "cf-ID: " + name + "\r\n";
    text += "cf-rating: " + str(now_rating) + "\r\n"
    text += "cf-Max-rating: " + str(max_rating) + "\r\n"
    text += "cf-最高排名：" + str(maxs) + "\r\n"
    if len(city) != 0:
        text += "city: " + city + "\r\n"
    if len(organize) != 0:
        text += "机构: " + organize + "\r\n"
    text += "\r\n最近的cf比赛：\r\n"
    text +="比赛名称：" + contestname + "\r\n"
    text +="比赛排名：" + str(rank) + "\r\n"
    text +="比赛得分：" + str(score) + "\r\n"
    return text








print(getCodeforceMsg("zhaobo"))
