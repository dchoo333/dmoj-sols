from collections import deque

n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
g = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = map(int, input().split())
    g[x].append(y); g[y].append(x)

t = [set() for _ in range(n + 1)]
tg = [0] * (n + 1)
sn = [0] * (n + 1)
for s in range(1, n + 1):
    if sn[s]: continue
    sn[s] = 1; c = [s]
    for u in c:
        for w in g[u]:
            if not sn[w]:
                sn[w] = 1; c.append(w)
                t[u].add(w); t[w].add(u)
    for p, v in zip(sorted(c), sorted(a[x] for x in c)): tg[p] = v

ps = [0] * (n + 1)
for i in range(1, n + 1): ps[a[i]] = i

o = []
q = [v for v in range(1, n + 1) if len(t[v]) == 1]
while q:
    v = q.pop()
    if not t[v]: continue
    u = ps[tg[v]]
    if u != v:
        pr = {u: 0}; d = deque([u])
        while v not in pr:
            x = d.popleft()
            for y in t[x]:
                if y not in pr: pr[y] = x; d.append(y)
        h = [v]
        while h[-1] != u: h.append(pr[h[-1]])
        h.reverse()
        for i in range(len(h) - 1):
            x, y = h[i], h[i + 1]
            a[x], a[y] = a[y], a[x]
            ps[a[x]] = x; ps[a[y]] = y
            o.append(f"{x} {y}")
    w = next(iter(t[v]))
    t[w].discard(v); t[v].clear()
    if len(t[w]) == 1: q.append(w)

print(len(o))
print(*a[1:])
if o: print("\n".join(o))