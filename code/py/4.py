
# -*- coding: gbk -*- 
def judge(years):
    if (years % 4 == 0 and years % 100 != 0) or (years % 400 == 0):
        return True
    else:
        return False

months = {1: 31,2: 28,3: 31,4: 30,5: 31,6: 30,7: 31,8: 31,9: 30,10: 31,11: 30,12: 31}

while True:

    year,month,day = map(str,input("请输入日期:\n").split('-'))

    try:
        year = int(year)
        month = int(month)
        day = int(day)
    except ValueError:
        print("输入不合法请重现输入")
        continue
        

    Ans = 0

    for i in range(1,13):
        if i<month:
            if i==2 and judge(year) == True:
                Ans = Ans + months[i] + 1
            else:
                Ans = Ans + months[i]

    Ans = Ans + day

    print(Ans)
