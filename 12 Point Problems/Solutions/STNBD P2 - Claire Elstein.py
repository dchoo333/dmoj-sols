import sys
from array import array
f = sys.stdin.buffer
n, m = map(int, f.readline().split())
M = 10 ** 9 + 7

U = array('i'); V = array('i')
od = array('i', bytes(4 * (n + 1)))
ind = array('i', bytes(4 * (n + 1)))
for ln in f:
    s = ln.split()
    if not s: continue
    u = int(s[0]); v = int(s[1])
    U.append(u); V.append(v)
    od[u] += 1; ind[v] += 1

m = len(U)
st = array('i', bytes(4 * (n + 2)))
for u in range(1, n + 1): st[u + 1] = st[u] + od[u]
A = array('i', bytes(4 * m))
p = array('i', st)
for u, v in zip(U, V):
    A[p[u]] = v; p[u] += 1
del U, V, p

c = array('q', bytes(8 * (n + 1)))
l = array('q', bytes(8 * (n + 1)))
for v in range(1, n + 1):
    if not ind[v]: c[v] = 1

for u in range(1, n + 1):
    cu = c[u]
    t = (l[u] + cu) % M
    for k in range(st[u], st[u + 1]):
        v = A[k]
        c[v] = (c[v] + cu) % M
        l[v] = (l[v] + t) % M

print(sum(l[v] for v in range(1, n + 1) if not od[v]) % M)