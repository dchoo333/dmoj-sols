from collections import deque

r, c, t = map(int, input().split())
g = [input() for _ in range(r)]

pts = []
for i in range(r):
    for j in range(c):
        if g[i][j] == 'G': pts.insert(0, (i, j))
        elif g[i][j] == 'H': pts.append((i, j))

def bfs(s):
    d = [[-1] * c for _ in range(r)]
    d[s[0]][s[1]] = 0
    q = deque([s])
    while q:
        x, y = q.popleft()
        for a, b in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if 0 <= a < r and 0 <= b < c and g[a][b] != 'X' and d[a][b] < 0:
                d[a][b] = d[x][y] + 1
                q.append((a, b))
    return [d[p][q2] for p, q2 in pts]

D = [bfs(p) for p in pts]
k = len(pts) - 1
INF = float('inf')

dp = [[INF] * k for _ in range(1 << k)]
for i in range(k): dp[1 << i][i] = D[0][i + 1]
for m in range(1, 1 << k):
    for i in range(k):
        v = dp[m][i]
        if v == INF or not m >> i & 1: continue
        for j in range(k):
            if not m >> j & 1:
                nm = m | 1 << j
                w = v + D[i + 1][j + 1]
                if w < dp[nm][j]: dp[nm][j] = w

print(min(dp[(1 << k) - 1]))