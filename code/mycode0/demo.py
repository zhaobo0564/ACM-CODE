
from datetime import datetime

import nonebot
import pytz
from aiocqhttp.exceptions import Error as CQHttpError
import json
import requests
from bs4 import BeautifulSoup



def judge(year):
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
    if day== 30 and month == 2 and judge(year): #判断是否为闰年
        month += 1
        day -= 29
    elif day == 29 and month == 2 and judge(year) == False:
        day -= 28
        month += 1
    elif day == 31 and month in (4, 6 , 9 ,11):
        day -= 30
        month += 1
    elif day == 32:
        day -= 31
        month += 1
    if month >12 :
        month = 1
        year += 1
    if (min < 10):
        time = ("%s-%s-%s %s:0%s") % (year, month, day, hr, min)
    else:
        time = ("%s-%s-%s %s:%s") % (year, month, day, hr, min)
    return time
        
if __name__ == "__main__":
    
    time = '12 Apr 2020  17:35:00'


    date = datetime.strptime(time, '%d %b %Y  %H:%M:%S')
    print(change(date=date, hour=5, minute=0))  
    {"group": [818692628, 593466006, 854591549, 576860735]}