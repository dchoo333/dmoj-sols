from collections import deque

R, C = map(int, input().split())
L, W = map(int, input().split())
g = [input() for _ in range(R)]

s = [[0] * (C + 1) for _ in range(R + 1)]
for i in range(R):
    row = g[i]; a = s[i]; b = s[i + 1]
    for j in range(C):
        b[j + 1] = b[j] + a[j + 1] - a[j] + (row[j] == '#')

h, w = R - L + 1, C - W + 1
ok = bytearray(h * w)
for i in range(h):
    a = s[i]; b = s[i + L]
    for j in range(w):
        if b[j + W] - a[j + W] - b[j] + a[j] == 0: ok[i * w + j] = 1

t = h * w - 1
if not ok[0] or not ok[t]:
    print(-1)
else:
    d = [-1] * (h * w)
    d[0] = 0
    q = deque([0])
    while q:
        u = q.popleft()
        if u == t: break
        i, j = divmod(u, w)
        du = d[u] + 1
        if i > 0 and ok[u - w] and d[u - w] < 0: d[u - w] = du; q.append(u - w)
        if i < h - 1 and ok[u + w] and d[u + w] < 0: d[u + w] = du; q.append(u + w)
        if j > 0 and ok[u - 1] and d[u - 1] < 0: d[u - 1] = du; q.append(u - 1)
        if j < w - 1 and ok[u + 1] and d[u + 1] < 0: d[u + 1] = du; q.append(u + 1)
    print(d[t])