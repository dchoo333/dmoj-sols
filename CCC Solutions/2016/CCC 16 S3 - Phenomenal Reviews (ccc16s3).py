from collections import deque

n, m = map(int, input().split())
pho = [False]*n
for x in map(int, input().split()):
    pho[x] = True

g = [[] for _ in range(n)]
deg = [0]*n
for _ in range(n-1):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)
    deg[a] += 1
    deg[b] += 1

def prune():
    q = deque()
    vis = [0]*n
    for i in range(n):
        if deg[i] == 1:
            q.append(i)
            vis[i] = 1
    while q:
        u = q.popleft()
        if not pho[u]:
            for v in g[u]:
                deg[v] -= 1
                if deg[v] <= 1 and not vis[v]:
                    vis[v] = 1
                    q.append(v)
            deg[u] = 0

prune()

def bfs(u):
    q = deque([u])
    vis = [False]*n
    vis[u] = True
    cnt = 0
    while q:
        for _ in range(len(q)):
            cur = q.popleft()
            for v in g[cur]:
                if deg[v] > 0 and not vis[v]:
                    vis[v] = True
                    q.append(v)
        cnt += 1
    return cur, cnt-1

fs = next(i for i in range(n) if deg[i] > 0)
tot = sum(1 for x in deg if x > 0)*2 - 2
_, d = bfs(bfs(fs)[0])
print(tot - d)
