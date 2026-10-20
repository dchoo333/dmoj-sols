import sys
r = sys.stdin.buffer.readline
n, m = map(int, r().split())
mt = [0] * (n + 1)
for i in range(1, n + 1): mt[i] = int(r())

E = []
for _ in range(m):
    u, v, c = r().split()
    E.append(int(c) << 36 | int(u) << 18 | int(v))
E.sort()

p = list(range(n + 1))
K = (1 << 18) - 1

def f(x):
    while p[x] != x:
        p[x] = p[p[x]]; x = p[x]
    return x

L = 1; s = 0; a = -1
for e in E:
    c = e >> 36; u = e >> 18 & K; v = e & K
    if c > L:
        s += (c - L) * mt[f(1)]; L = c
    ru, rv = f(u), f(v)
    if ru != rv:
        p[ru] = rv
        if mt[ru] < mt[rv]: mt[rv] = mt[ru]
    if f(1) == f(n): a = s; break

print(a)