import sys
from sys import stdin as i, stdout as o

l = i.readline().split()
n, c, q = int(l[0]), int(l[1]), int(l[2])

def a(x, y):
    o.write(f"? {x} {y}\n")
    o.flush()
    r = int(i.readline())
    if r == -1:
        sys.exit()
    return r

s = set()

lo, hi = 1, c
while lo < hi:
    m = (lo + hi) // 2
    if a(0, m) < m:
        hi = m
    else:
        lo = m + 1
x = lo
p = a(0, x)

l2, h2 = x, min(c, x + p)
while l2 < h2:
    m = (l2 + h2) // 2
    v1 = a(0, m)
    v2 = a(0, m + 1)
    if v1 > v2:
        l2 = m + 1
    else:
        h2 = m
s2 = l2

s1 = a(0, s2)
s.add(s1)
s.add(s2)

lr, hr = 0, c - 1
while lr < hr:
    m = (lr + hr + 1) // 2
    if a(m, c) < c - m:
        lr = m
    else:
        hr = m - 1
xr = lr
pr = a(xr, c)

l3, h3 = max(0, xr - pr), xr
while l3 < h3:
    m = (l3 + h3 + 1) // 2
    v1 = a(m, c)
    v2 = a(m - 1, c)
    if v1 > v2:
        h3 = m - 1
    else:
        l3 = m
sn1 = l3
sn = c - a(sn1, c)
s.add(sn1)
s.add(sn)

def f(L, R):
    if R - L <= 3:
        return
    M = (L + R) // 2
    t = a(L, M)
    if t == M - L:
        return
    t2 = a(L, M + 1)
    if t2 == t - 1:
        z = M + t
    else:
        z = M - t
    s.add(z)
    f(L, z)
    f(z, R)

k = sorted(s)
for j in range(len(k) - 1):
    f(k[j], k[j + 1])

r = sorted(s)
o.write("! " + " ".join(map(str, r)) + "\n")
o.flush()