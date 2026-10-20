from collections import deque

def toks():
    while True:
        for x in input().split(): yield int(x)

it = toks()
m = next(it); n = next(it); l = next(it)
mem = [next(it) for _ in range(l)]

rg = []
for _ in range(m):
    k = next(it)
    rg.append([next(it) for _ in range(k)])

ed = {}
at = [[] for _ in range(n + 1)]
for r, b in enumerate(rg):
    for i in range(len(b)):
        u, v = b[i], b[(i + 1) % len(b)]
        ed.setdefault((min(u, v), max(u, v)), []).append(r)
        at[u].append(r)

adj = [set() for _ in range(m)]
for rs in ed.values():
    for a in rs:
        for b in rs:
            if a != b: adj[a].add(b)

tot = [0] * m
for t in mem:
    d = [-1] * m
    q = deque()
    for r in set(at[t]):
        d[r] = 0; q.append(r)
    while q:
        x = q.popleft()
        for y in adj[x]:
            if d[y] < 0: d[y] = d[x] + 1; q.append(y)
    for r in range(m): tot[r] += d[r]

b = min(range(m), key=lambda r: tot[r])
print(tot[b])
print(b + 1)