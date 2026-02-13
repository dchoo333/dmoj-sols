from collections import deque
from math import inf

n = int(input())
g = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    g[a].append(b)
    g[b].append(a)

p = input()
c = list(map(int, input().split()))

par = [-1] * n
ch = [[] for _ in range(n)]
dep = [0] * n
q = deque([0])
while q:
    u = q.popleft()
    for v in g[u]:
        if v != par[u]:
            par[v] = u
            ch[u].append(v)
            dep[v] = dep[u] + 1
            q.append(v)

d2n = [[] for _ in range(max(dep) + 1)]
for i in range(n):
    d2n[dep[i]].append(i)

dp = [[0] * n for _ in range(3)]
for d in range(len(d2n) - 1, -1, -1):
    for u in d2n[d]:
        c1 = c[u] + sum(dp[1][v] for v in ch[u])
        c2 = 0
        valid = True
        for v in ch[u]:
            c2 += dp[0][v]
            if c2 >= inf:
                valid = False
                break
        dp[1][u] = min(c1, c2)

        if p[u] == 'Y':
            dp[0][u] = dp[1][u]
            dp[2][u] = c1
            continue

        s1 = sum(dp[1][v] for v in ch[u])
        c3 = inf
        for v in ch[u]:
            c3 = min(c3, s1 - dp[1][v] + dp[2][v])
        c3 += c[u]

        c4 = inf
        if valid:
            s2 = sum(dp[0][v] for v in ch[u])
            for v in ch[u]:
                if dp[2][v] < inf:
                    c4 = min(c4, s2 - dp[0][v] + dp[2][v])

        dp[0][u] = min(c3, c4)
        dp[2][u] = c3

print(dp[0][0])


