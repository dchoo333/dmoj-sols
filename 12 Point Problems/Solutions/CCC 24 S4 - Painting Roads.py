import sys
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
g = [[] for _ in range(n+1)]
ans = ['G']*m
vis = [0]*(n+1)

def dfs(node, prv):
    for v, i in g[node]:
        if not vis[v]:
            vis[v] = 1
            ans[i] = 'B' if prv=='R' else 'R'
            dfs(v, ans[i])

for i in range(m):
    a, b = map(int, input().split())
    g[a].append((b, i))
    g[b].append((a, i))

for i in range(1, n+1):
    if not vis[i]:
        vis[i] = 1
        dfs(i, 'B')

print(''.join(ans))
