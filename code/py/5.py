ans = 0
for i in range(1, 9999991):
    s = str(i)
    one = 0
    one1 = 0
    zero = 0
    for it in s:
        if(one == 0 and it == '1'):
            one = 1
        elif(one and one1 == 0 and it == '1'):
            one1 = 1
        elif(one and one1 and zero == 0 and it =='0'):
            zero = 1
            ans += 1
            break
    
print(ans)