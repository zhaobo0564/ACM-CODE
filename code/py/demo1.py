from nonebot import on_command, CommandSession
from bs4 import BeautifulSoup
import requests
from datetime import datetime
import json
import random
import pymysql
 

account = {
    'user' : 'root',
    'password' : 'zhaobo123..',
    'host' : '193.112.141.129',
    'database' : 'daan'
}

def mysqlConnect(account):
    connect = pymysql.connect(**account)
    return connect

def insertMsg(qq, question, answer):
    connect = mysqlConnect(account)
    cursor = connect.cursor(cursor = pymysql.cursors.DictCursor)
    try:
        sql = "INSERT INTO msg VALUES(\'%s\', \'%s\', \'%s\')"%(question, answer, qq)
        cursor.execute()
    except:
        pass

def insertwrongMsg(qq, question):
    connect = mysqlConnect(account)
    cursor = connect.cursor(cursor = pymysql.cursors.DictCursor)
    try:
        sql = "INSERT INTO wmsg VALUES(\'%s\', \'%s\')"%(question, qq)
        cursor.execute()
    except:
        pass


def getMsg(qq, question):
    url = "http://wk.xlqwlcm.cn/wkcx//web.php?question=%s"%(question)
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0)Gecko/20100101 Firefox/66.0"
    }
    r = requests.get(url, timeout=30, headers=headers)
    html = r.text
    data = json.loads(html)
    answer = data['answer']
    if 'QQ' in answer:
        print("找不到")
        insertwrongMsg(qq, question)
        return ""
    else:
        insertMsg(qq, question, answer)
        return answer



@on_command('answer',aliases=('an'))
async def getAnswer(session: CommandSession):
    msg = session.ctx['message']
    msg = str(msg)
    msg = msg.split()
    message_type = session.ctx['message_type']
    qq = session.ctx['user_id']
    ai = "[CQ:at,qq=%s]"%qq
    question = "".join(msg[1:])
    ans = getAnswer(str(qq), question)
    if ans is None:
        if (message_type == 'group'):
            await session.bot.send_group_msg(group_id=session.ctx['group_id'], message=ai +"找不到该题[CQ:face,id=106]")
        elif (message_type == 'private'):
            await session.bot.send_private_msg(user_id=session.ctx['user_id'], message="找不到该题[CQ:face,id=106]")
    else:
        if (message_type == 'group'):
            await session.bot.send_group_msg(group_id=session.ctx['group_id'], message=ai +ans)
        elif (message_type == 'private'):
            await session.bot.send_private_msg(user_id=session.ctx['user_id'], message=ans)




    

    

