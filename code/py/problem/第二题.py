# -*- coding: gbk -*- 
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


# 建立商品与价格的映射
price = {
    'ITEM0001': 10,
    'ITEM0013': 20,
    'ITEM0022': 30
}

msg = "ITEM0001 x 1, ITEM0013 x 2, ITEM0022 x 1"

msg = list(msg.split(','))
answer = []
money = 0
for i in msg:
    answer.append(work(i))
for i in answer:
    for j in i:
        if j in price.keys():
            money = money + price[j] * i[j]
        else:
            print("商品不存在")
            exit(0)
print(money)



