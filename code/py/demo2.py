from nonebot import on_command, CommandSession
from bs4 import BeautifulSoup
import requests
from datetime import datetime
import json
import random
import pymysql

url = "https://www.150s.cn/"
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0)Gecko/20100101 Firefox/66.0"
}
r = requests.get(url, timeout=30, headers=headers)
html = r.text
print(html)