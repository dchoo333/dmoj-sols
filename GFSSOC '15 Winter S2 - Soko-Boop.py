from collections import deque

r, c = map(int, input().split())
g = [input()[:c] for _ in range(r)]
n = r * c

ps = bs = tg = 0
for i in range(r):
    for j in range(c):
        k = i * c + j
        if g[i][j] == 'P': ps = k
        elif g[i][j] == 'B': bs = k
        elif g[i][j] == 'X': tg = k

nx = [[-1] * 4 for _ in range(n)]
for i in range(r):
    for j in range(c):
        for k, (a, b) in enumerate(((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1))):
            if 0 <= a < r and 0 <= b < c and g[a][b] != '#': nx[i * c + j][k] = a * c + b

vis = bytearray(n * n)
s0 = ps * n + bs
vis[s0] = 1
q = deque([s0])
dist = 0
ans = -1

while q and ans < 0:
    dist += 1
    for _ in range(len(q)):
        s = q.popleft()
        p, b = divmod(s, n)
        for k in range(4):
            a = nx[p][k]
            if a < 0: continue
            nb = b
            if a == b:
                nb = nx[b][k]
                if nb < 0: continue
            ns = a * n + nb
            if vis[ns]: continue
            vis[ns] = 1
            if nb == tg: ans = dist; break
            q.append(ns)
        if ans >= 0: break

print(ans)