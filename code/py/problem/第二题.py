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
answer = []
money = 0
for i in msg:
    answer.append(work(i))
for i in answer:
    for j in i:
        if j in price.keys():
            money = money + price[j] * i[j]
        else:
            print("��Ʒ������")
            exit(0)
print(money)



