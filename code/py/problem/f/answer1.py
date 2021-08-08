# -*- coding: gbk -*- 

#思路就是将字符串提取出来，将数量也提取出来放，放入一个字典中

def work(msg):
    answer = {}
    keys = ""
    values = 0
    f = 0               # f = 0提取名称，f = 1提取数量
    for i in msg:
        if i == 'x':    # 说明名称已经提取完毕
            f = 1
        else:
            if i == ' ':
                continue    # 删掉没用的空格
            if f == 0:
                keys = keys + i
            elif f == 1:
                values = values * 10 + int(i, 10)  # 将数量的字符串转为10进制数
    answer[keys] = values
    return answer

msg = "ITEM0001 x 1, ITEM0013 x 2, ITEM0022 x 1"
msg = list(msg.split(','))
answer = []
for i in msg:
    answer.append(work(i))

print(answer)






