# -*- coding: gbk -*- 
def work(msg):
    answer = {}
    keys = ""
    values = 0
    f = 0               # f = 0��ȡ���ƣ�f = 1��ȡ����
    for i in msg:
        if i == 'x':    # ˵�������Ѿ���ȡ���
            f = 1
        else:
            if i == ' ':
                continue    # ɾ��û�õĿո�
            if f == 0:
                keys = keys + i
            elif f == 1:
                values = values * 10 + int(i, 10)  # ���������ַ���תΪ10������
    answer[keys] = values
    return answer


# ������Ʒ��۸��ӳ��
price = {
    'ITEM0001': 10,
    'ITEM0013': 20,
    'ITEM0022': 30
}

msg = "ITEM0001 x 1, ITEM0013 x 2, ITEM0022 x 1"

msg = list(msg.split(','))
flag_001 = 0 # ��¼001��Ʒ�Ƿ���
flag_022 = 0 # ��¼022��Ʒ�Ƿ���
answer = []
money = 0
half_goods = 0 # ��¼�����Ʒ�Ľ��
for i in msg:
    answer.append(work(i))

for i in answer:
    for j in i:
        if j not in price.keys():
            print("��Ʒ������")
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
    half_goods = half_goods * 0.5       # ���
money = money + half_goods
if money >= 100:
    money = money - 30              # �ܽ����100 �Ż�30

print(money)

