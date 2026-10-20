import sys, heapq
D = sys.stdin.buffer.read().split()
n, m = int(D[0]), int(D[1])
T = [0] + [int(x) for x in D[2:2 + n]]
g = [[] for _ in range(n + 1)]
p = 2 + n
for _ in range(m):
    a, b, c = int(D[p]), int(D[p + 1]), int(D[p + 2]); p += 3
    g[a].append((b, c)); g[b].append((a, c))
del D

I = float('inf')

def virgil(d):
    h = [(d[v], v) for v in range(1, n + 1) if d[v] < I]
    heapq.heapify(h)
    while h:
        x, u = heapq.heappop(h)
        if x > d[u]: continue
        for v, w in g[u]:
            y = x + w
            if y < d[v]: d[v] = y; heapq.heappush(h, (y, v))
    return d

d = [I] * (n + 1); d[1] = 0
d = virgil(d)
for k in (1, 2, 3):
    e = [I] * (n + 1)
    for v in range(1, n + 1):
        if T[v] == k: e[v] = d[v]
    d = virgil(e)

a = min((d[v] for v in range(1, n + 1) if T[v] == 4), default=I)
print(-1 if a == I else a)