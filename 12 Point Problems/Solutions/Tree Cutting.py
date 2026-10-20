import heapq
R, C = map(int, input().split())
g = [input().split() for _ in range(R)]

sx = sy = mh = 0
for i in range(R):
    for j in range(C):
        if g[i][j] == 'X': sx, sy = i, j
        elif g[i][j] != '.': mh = max(mh, int(g[i][j]))

tx = ty = -1; bd = 1 << 30
for i in range(R):
    for j in range(C):
        v = g[i][j]
        if v not in '.X' and int(v) == mh:
            d = (i - sx) ** 2 + (j - sy) ** 2
            if d < bd: bd = d; tx, ty = i, j

I = (1 << 30, 0)
D = [[I] * C for _ in range(R)]
D[sx][sy] = (0, 0)
h = [(0, 0, sx, sy)]
while h:
    s, k, x, y = heapq.heappop(h)
    if (s, k) > D[x][y]: 
        continue
    if (x, y) == (tx, ty): 
        break
    for nx, ny in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
        if 0 <= nx < R and 0 <= ny < C:
            v = g[nx][ny]
            if (nx, ny) == (tx, ty) or v in '.X': c = (s, k)
            else: c = (s + int(v), k + 1)
            if c < D[nx][ny]:
                D[nx][ny] = c
                heapq.heappush(h, (c[0], c[1], nx, ny))

print(D[tx][ty][1])