# -*- coding: gbk -*- 
import math
t = int(input())
while True:
    t = t - 1
    if t < 0:
        break
    k = int(input())
    f = 0
    for i in range(2, int(math.sqrt(k)) + 2):
        if k % i == 0:
            f = 1
            break   
    if f == 0:
        print(k)
    else:
        ans = 1
        res = 1
        while True:
            if ans % k == 0:
                print(res)
                break;
            ans = ans * (res + 1)
            res = res + 1