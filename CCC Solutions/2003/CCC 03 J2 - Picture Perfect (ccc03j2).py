def do(t, k):
    m = 0
    min_val = t[0]

    for i in range(1, k):
        if t[i] < min_val:
            min_val = t[i]
            m = i

    return m

def z(x, p):
    return p // 2 - x

def calc(x, area):
    return (x + area // x) * 2

a = [0] * 10000
b = [0] * 10000
c = [0] * 10000

total_line = 0

for i in range(100000):
    c[i] = int(input())
    if c[i] == 0:
        total_line = i
        break

for j in range(total_line):
    k = 0
    for x in range(1, c[j] // 2):
        if c[j] % x == 0:
            a[k] = x
            b[k] = (x + c[j] // x) * 2
            k += 1

    m = do(b, k)

    if c[j] <= 3:
        b[m] = 4 if c[j] == 1 else 6 if c[j] == 2 else 8
        a[m] = 1

    print(f"Minimum perimeter is {b[m]} with dimensions {a[m]} x {z(a[m], b[m])}")
