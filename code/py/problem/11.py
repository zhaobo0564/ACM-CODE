a, b, m, n = map(int, input().split(' '))

fn = []

for i in range (0, n + 10):
    fn.append(0)

fn[1] = 1
fn[2] = 1

for i in range(3, n + 1):
    fn[i] = a * fn[i - 1] + b * fn[i - 2]

print(fn[n])