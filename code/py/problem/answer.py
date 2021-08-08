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
flag_001 = 0 # 记录001商品是否购买
flag_022 = 0 # 记录022商品是否购买
answer = []
money = 0
half_goods = 0 # 记录半价商品的金额
for i in msg:
    answer.append(work(i))

for i in answer:
    for j in i:
        if j not in price.keys():
            print("商品不存在")
            exit(0)
        if j == 'ITEM0001':
            flag_001 = 1
            half_goods = half_goods + price[j] * i[j]

        elif j == 'ITEM0022':      
            flag_022 = 1
            half_goods = half_goods + price[j] * i[j]
        else:
            money = money + price[j] * i[j]
        

if flag_001 == 1 and flag_022 == 1:
    half_goods = half_goods * 0.5       # 半价
money = money + half_goods
if money >= 100:
    money = money - 30              # 总金额满100 优惠30

print(money)

