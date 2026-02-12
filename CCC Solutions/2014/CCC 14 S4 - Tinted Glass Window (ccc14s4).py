n = int(input())
t = int(input())

a = []
xs = []
ys = []

for _ in range(n):
    l, u, r, d, v = map(int, input().split())
    a.append((l, u, r, d, v))
    xs += [l, r]
    ys += [u, d]

rx = sorted(set(xs))
ry = sorted(set(ys))

cx = {x:i for i, x in enumerate(rx)}
cy = {y:i for i, y in enumerate(ry)}

h = len(ry)
w = len(rx)

g = [[0]*w for _ in range(h)]

for l, u, r, d, v in a:
    x1, x2 = cx[l], cx[r]
    y1, y2 = cy[u], cy[d]
    for i in range(y1, y2):
        g[i][x1] += v
        g[i][x2] -= v

ans = 0

for i in range(h-1):
    cur = 0
    for j in range(w-1):
        cur += g[i][j]
        if cur >= t:
            ans += (ry[i+1] - ry[i]) * (rx[j+1] - rx[j])

print(ans)
