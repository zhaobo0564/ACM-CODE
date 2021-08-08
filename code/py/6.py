s = "algorithm, bitset, cctype, cerrno, clocale, cmath, complex, cstdio, cstdlib, cstring, ctime, deque, exception, fstream, functional, limits, list, map, iomanip, ios, iosfwd, iostream, istream, ostream, queue, set, sstream, stack, stdexcept, streambuf, string, utility, vector, cwchar, cwctype"
s = s.split(', ')

t = int(input())
for i in range(0, t):
    a = str(input())
    f = 0
    for j in s:
        if a == j:
            print("Qian")
            f = 1
            break
    if f == 0:
        print("Kun")
        