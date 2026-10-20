import sys, heapq
D = sys.stdin.buffer.read().split()
p = 0
n = int(D[p]); p += 1

g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v, w = int(D[p]), int(D[p + 1]), int(D[p + 2]); p += 3
    g[u].append((v, w)); g[v].append((u, w))

L = max(1, n.bit_length())
par = [0] * (n + 1)
dp = [0] * (n + 1)
lv = [0] * (n + 1)
par[1] = 1
st = [1]
vis = [False] * (n + 1); vis[1] = True
while st:
    u = st.pop()
    for v, w in g[u]:
        if not vis[v]:
            vis[v] = True; par[v] = u
            dp[v] = dp[u] + w; lv[v] = lv[u] + 1
            st.append(v)

up = [par]
for k in range(1, L):
    a = up[-1]
    up.append([a[a[v]] for v in range(n + 1)])

def lca(u, v):
    if lv[u] < lv[v]: u, v = v, u
    d = lv[u] - lv[v]; k = 0
    while d:
        if d & 1: u = up[k][u]
        d >>= 1; k += 1
    if u == v: return u
    for k in range(L - 1, -1, -1):
        a = up[k]
        if a[u] != a[v]: u = a[u]; v = a[v]
    return up[0][u]

def ds(u, v): return dp[u] + dp[v] - 2 * dp[lca(u, v)]

m, t = int(D[p]), int(D[p + 1]); p += 2
r = [0] + [int(x) for x in D[p:p + m]]; p += m
K = [None] * (m + 1)
for i in range(1, m + 1):
    k = int(D[p]); p += 1
    K[i] = [int(x) for x in D[p:p + k]]; p += k
s = int(D[p]); p += 1
S = [int(x) for x in D[p:p + s]]

I = float('inf')
d = [I] * (m + 1)
h = []
for b in S:
    if dp[r[b]] < d[b]:
        d[b] = dp[r[b]]; h.append((d[b], b))
heapq.heapify(h)

a = -1
while h:
    x, b = heapq.heappop(h)
    if x > d[b]: continue
    if b == t: a = x; break
    rb = r[b]
    for o in K[b]:
        y = x + ds(rb, r[o])
        if y < d[o]:
            d[o] = y; heapq.heappush(h, (y, o))

print(a)