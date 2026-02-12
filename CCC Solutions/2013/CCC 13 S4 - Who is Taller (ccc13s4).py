import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
g = [set() for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    g[u].add(v)

x, y = map(int, sys.stdin.readline().split())
if x == y:
    print("unknown")
    exit()

def f(s, t):
    v = [0] * (n + 1)
    q = deque([s])
    v[s] = 1
    while q:
        u = q.popleft()
        for w in g[u]:
            if w == t:
                return True
            if not v[w]:
                v[w] = 1
                q.append(w)
    return False

if f(x, y):
    print("yes")
elif f(y, x):
    print("no")
else:
    print("unknown")
