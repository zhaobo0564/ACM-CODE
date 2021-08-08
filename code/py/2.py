
# -*- coding: gbk -*- 
x = list(input().split(' '))
a = int(x[0])
b = int(x[1])
s = list(x[2])
s.reverse()
base = 1
ans = 0
for i in s:
    if i >= 'A' and i <= 'Z':
        cnt = ord(i) - ord('A') + 10
        ans = ans + cnt * base
    elif i >= 'a' and i <= 'z':
        cnt = ord(i) - ord('a') + 36
        ans = ans + cnt * base
    else:
        cnt = ord(i) - ord('0')
        ans = ans + cnt * base
    base = base * a

res = []
while True:
    res.append(ans % b)
    ans = ans // b;
    if ans == 0:
        break
res.reverse()
for i in res:
    if (i >= 10 and i < 36):
        print(chr(i - 10 + ord('A')), end = '')
    elif i >= 36:
        print(chr(i - 36 + ord('a')), end = '')
    else:
        print(i, end='')
print()





