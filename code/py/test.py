import datetime
a = input().split(":")
b = input().split(":")
d1 = datetime.datetime(2018,10,22,int(a[0], 10),a[1],a[2])
d2 = datetime.datetime(2018,10,22,b[0],b[1],b[2])

d = d2 - d1
print(d.seconds)