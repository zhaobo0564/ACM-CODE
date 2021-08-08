
a = str(input())
a = a.split('+')

ans = 0.0


for it in a:
    if 'd' in it:
        cnt = it.split('d')
       # print(cnt)
        cat = (1 + int(cnt[1], 10)) / 2
        cat = int(cnt[0], 10) * cat
        ans += cat
    else:
        ans += int(it, 10)

cn = int(ans)
if cn == ans:
    print(cn)
else:
     print(ans)
