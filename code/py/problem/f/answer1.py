# -*- coding: gbk -*- 

#˼·���ǽ��ַ�����ȡ������������Ҳ��ȡ�����ţ�����һ���ֵ���

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

msg = "ITEM0001 x 1, ITEM0013 x 2, ITEM0022 x 1"
msg = list(msg.split(','))
answer = []
for i in msg:
    answer.append(work(i))

print(answer)






