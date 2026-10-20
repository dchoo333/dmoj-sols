import sys, heapq
from math import atan2, sqrt

t = sys.stdin.buffer.read().split()
n, m = int(t[0]), int(t[1]); R = float(t[2]); T = float(t[3]); k = int(t[4]); p = 5
air = [int(t[p + i]) - 1 for i in range(k)]; p += k

v = [0] * n; X = [0.0] * n; Y = [0.0] * n; Z = [0.0] * n
for i in range(n):
    v[i] = int(t[p]); X[i] = float(t[p + 1]); Y[i] = float(t[p + 2]); Z[i] = float(t[p + 3]); p += 4

g = [[] for _ in range(n)]
for _ in range(m):
    a = int(t[p]) - 1; b = int(t[p + 1]) - 1; p += 2
    if a == b: continue
    cx = Y[a] * Z[b] - Z[a] * Y[b]
    cy = Z[a] * X[b] - X[a] * Z[b]
    cz = X[a] * Y[b] - Y[a] * X[b]
    dot = X[a] * X[b] + Y[a] * Y[b] + Z[a] * Z[b]
    w = R * atan2(sqrt(cx * cx + cy * cy + cz * cz), dot)
    g[a].append((b, w)); g[b].append((a, w))

INF = float('inf')

def dij(src):
    d = [INF] * n
    h = [(0.0, s) for s in src]
    for s in src: d[s] = 0.0
    heapq.heapify(h)
    while h:
        du, u = heapq.heappop(h)
        if du > d[u]: continue
        for x, c in g[u]:
            nd = du + c
            if nd < d[x]:
                d[x] = nd
                heapq.heappush(h, (nd, x))
    return d

d1 = dij([0])
d2 = dij(air)

best = -1
lim = T - 1e-9
for i in range(n):
    if d1[i] + d2[i] < lim and v[i] > best: best = v[i]
print(best)