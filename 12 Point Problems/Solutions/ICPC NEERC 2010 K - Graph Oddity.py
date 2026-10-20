from collections import deque

n, m = map(int, input().split())
g = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a].append(b); g[b].append(a)

k = max(len(g[v]) for v in range(1, n + 1))
if k % 2 == 0: k += 1

r = next(v for v in range(1, n + 1) if len(g[v]) < k)

seen = [False] * (n + 1)
seen[r] = True
order = [r]
q = deque([r])
while q:
    u = q.popleft()
    for v in g[u]:
        if not seen[v]:
            seen[v] = True
            order.append(v)
            q.append(v)

col = [0] * (n + 1)
for v in reversed(order):
    used = {col[u] for u in g[v]}
    c = 1
    while c in used: c += 1
    col[v] = c

print(k)
print("\n".join(str(col[v]) for v in range(1, n + 1)))