import sys, heapq
D = sys.stdin.buffer.read().split()
n, m = int(D[0]), int(D[1])
g = [[] for _ in range(n + 1)]
p = 2
for i in range(m):
    u, v, w = int(D[p]), int(D[p + 1]), int(D[p + 2]); p += 3
    g[u].append((v, w, i)); g[v].append((u, w, i))
S, E = int(D[p]), int(D[p + 1])

cl = [0] * (n + 1)
st = [0] * (n + 1)
dp = [0] * (n + 1)
par = [0] * (n + 1)
pe = [-1] * (n + 1)
it = [0] * (n + 1)
for r in range(1, n + 1):
    if st[r]: continue
    st[r] = 1; stk = [r]
    while stk:
        u = stk[-1]
        if it[u] < len(g[u]):
            v, w, i = g[u][it[u]]; it[u] += 1
            if i == pe[u]: continue
            if st[v] == 0:
                st[v] = 1; par[v] = u; pe[v] = i; dp[v] = dp[u] + w
                stk.append(v)
            elif st[v] == 1:
                L = dp[u] - dp[v] + w
                x = u
                while x != v: cl[x] = L; x = par[x]
                cl[v] = L
        else:
            st[u] = 2; stk.pop()

I = float('inf')

def virgil(s):
    d = [I] * (n + 1); d[s] = 0
    h = [(0, s)]
    while h:
        x, u = heapq.heappop(h)
        if x > d[u]: continue
        for v, w, _ in g[u]:
            if x + w < d[v]: d[v] = x + w; heapq.heappush(h, (x + w, v))
    return d

a, b = virgil(S), virgil(E)
r = min((a[v] + b[v] + cl[v] for v in range(1, n + 1) if cl[v]), default=I)
print(-1 if r == I else r)