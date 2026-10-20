from collections import defaultdict

n = int(input())
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    g[a].append((b, c)); g[b].append((a, c))

par = [0] * (n + 1)
tin = [0] * (n + 1); tout = [0] * (n + 1)
par[1] = -1
st = [(1, 0)]
t = 0
while st:
    v, i = st.pop()
    if i == 0: tin[v] = t; t += 1
    if i < len(g[v]):
        st.append((v, i + 1))
        u = g[v][i][0]
        if u != par[v]:
            par[u] = v
            st.append((u, 0))
    else:
        tout[v] = t

d = [0] * (n + 1)
def mark(l, r):
    d[l] += 1; d[r] -= 1

for v in range(1, n + 1):
    by = defaultdict(list)
    for u, c in g[v]: by[c].append(u)
    for us in by.values():
        if len(us) < 2: continue
        for u in us:
            if par[u] == v: mark(tin[u], tout[u])
            else:
                mark(0, n)
                d[tin[v]] -= 1; d[tout[v]] += 1

cur = 0
bad = [0] * n
for i in range(n):
    cur += d[i]
    bad[i] = cur

r = [v for v in range(1, n + 1) if bad[tin[v]] == 0]
print(len(r))
if r: print("\n".join(map(str, r)))