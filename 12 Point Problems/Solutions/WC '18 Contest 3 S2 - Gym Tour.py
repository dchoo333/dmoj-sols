import sys
from collections import deque
D = sys.stdin.buffer.read().split()
n, k, F = int(D[0]), int(D[1]), int(D[2])
G = [int(x) for x in D[3:3 + k]]
g = [[] for _ in range(n + 1)]
p = 3 + k
for _ in range(n - 1):
    a, b = int(D[p]), int(D[p + 1]); p += 2
    g[a].append(b); g[b].append(a)

par = [0] * (n + 1)
dep = [-1] * (n + 1)
dep[1] = 0
q = deque([1])
while q:
    u = q.popleft()
    for v in g[u]:
        if dep[v] < 0:
            dep[v] = dep[u] + 1; par[v] = u; q.append(v)

mk = bytearray(n + 1)
mk[1] = 1
t = 0
for x in G:
    while not mk[x]:
        mk[x] = 1; t += 1; x = par[x]

e = 0
x = F
while not mk[x]:
    mk[x] = 1; e += 1; x = par[x]

print(min(2 * t - max(dep[x] for x in G), t + e))