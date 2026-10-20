import sys
from bisect import bisect_left, bisect_right
D = sys.stdin.buffer.read().split()
n = int(D[0])
ev = []
p = 1
for i in range(n):
    if D[p] == b'1': ev.append((int(D[p + 1]), -1)); p += 2
    else: ev.append((int(D[p + 1]), int(D[p + 2]))); p += 3

P = sorted(x for x, r in ev if r < 0)
m = len(P)
cv = [n] * m
nx = list(range(m + 1))

def f(x):
    while nx[x] != x:
        nx[x] = nx[nx[x]]; x = nx[x]
    return x

for t, (a, r) in enumerate(ev):
    if r < 0: continue
    lo = bisect_left(P, a - r); hi = bisect_right(P, a + r)
    j = f(lo)
    while j < hi:
        cv[j] = t; nx[j] = j + 1; j = f(j + 1)

d = [0] * (n + 1)
for t, (a, r) in enumerate(ev):
    if r >= 0: continue
    c = cv[bisect_left(P, a)]
    if c > t: d[t] += 1; d[c] -= 1

o = []; s = 0
for t in range(n):
    s += d[t]; o.append(s)
print("\n".join(map(str, o)))