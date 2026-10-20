import sys
D = sys.stdin.buffer.read().split()
n = int(D[0])
b = [int(x) for x in D[1:1 + n]]
c = [0] * (n + 1)
a = 0
k = 1

while k * k <= n:
    L = k * k
    g = 0
    for i in range(L):
        x = b[i]; y = c[x]
        if y == k: g -= 1
        y += 1
        if y == k: g += 1
        c[x] = y
    if g == k: a += 1
    for i in range(L, n):
        x = b[i]; y = c[x]
        if y == k: g -= 1
        y += 1
        if y == k: g += 1
        c[x] = y
        x = b[i - L]; y = c[x]
        if y == k: g -= 1
        y -= 1
        if y == k: g += 1
        c[x] = y
        if g == k: a += 1
    for i in range(n - L, n): c[b[i]] = 0
    k += 1

print(a)