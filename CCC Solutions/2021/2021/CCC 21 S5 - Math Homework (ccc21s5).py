from collections import Counter
from math import floor, log2, gcd, lcm

n, m = map(int, input().split())
q, r = [], []
for _ in range(m):
    x, y, z = map(int, input().split())
    q.append((x, y, z))
    r += [(x, 1, z), (y + 1, -1, z)]

d = Counter()
c, p = 1, 1
l = []
for x, y, z in sorted(r):
    l += [c] * (x - p)
    d[z] += y
    keys = [k for k, v in d.items() if v > 0]
    c = lcm(*keys) if keys else 1
    p = x

l += [1] * (n - len(l))

t = [l[:]]
for i in range(1, floor(log2(n)) + 1):
    t.append([gcd(t[i - 1][j], t[i - 1][j + 2 ** (i - 1)]) for j in range(n - 2 ** i + 1)])

f = 0
for x, y, z in q:
    a, b = x - 1, y - 1
    if a == b:
        f = 1 if l[a] != z else f
        continue
    s = b - a + 1
    i = floor(log2(s))
    if gcd(t[i][a], t[i][b - 2 ** i + 1]) != z:
        f = 1

if f:
    print("Impossible")
else:
    print(*l)
