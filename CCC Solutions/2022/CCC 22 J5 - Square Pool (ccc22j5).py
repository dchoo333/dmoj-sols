n = int(input())
t = int(input())
ts = [tuple(map(int, input().split())) for _ in range(t)]
ts += [(0, 0), (n+1, n+1)]
t += 2
ans = 0

ts.sort()

for i in range(t):
    x1, y1 = ts[i]
    for j in range(i+1, t):
        x2, y2 = ts[j]
        if x2 <= x1 or y2 <= y1:
            continue
        ms = min(n-x1, y2-1)
        for x3, y3 in ts:
            if x3 <= x1 or y3 >= y2:
                continue
            ms = min(ms, max(x3-x1-1, y2-y3-1))
        ans = max(ans, ms)

print(ans)
