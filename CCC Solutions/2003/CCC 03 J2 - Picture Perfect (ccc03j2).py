a = [0] * 10000
b = [0] * 10000
c = [0] * 10000

n = 0
for i in range(100000):
    c[i] = int(input())
    if c[i] == 0:
        n = i
        break

for j in range(n):
    k = 0
    for x in range(1, c[j] // 2):
        if c[j] % x == 0:
            a[k] = x
            b[k] = (x + c[j] // x) * 2
            k += 1

    m = 0
    mn = b[0]
    for i in range(1, k):
        if b[i] < mn:
            mn = b[i]
            m = i

    if c[j] <= 3:
        b[m] = 4 if c[j] == 1 else 6 if c[j] == 2 else 8
        a[m] = 1

    print(f"Minimum perimeter is {b[m]} with dimensions {a[m]} x {b[m]//2 - a[m]}")
