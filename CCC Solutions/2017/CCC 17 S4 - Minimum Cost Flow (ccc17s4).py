p = list(range(100001))
n, m, k = map(int, input().split())
e = []

for i in range(1, m+1):
    a, b, c = map(int, input().split())
    e.append((c, 1 if i >= n else 0, a, b))

e.sort(key=lambda x: (x[0], x[1]))

ans = 0
for i in range(m):
    w, new, a, b = e[i]
    x, y = a, b
    while p[x] != x: p[x] = p[p[x]]; x = p[x]
    while p[y] != y: p[y] = p[p[y]]; y = p[y]
    if x != y:
        p[x] = y
        last = i
        lastw = w
        ans += new

if e[last][1] and lastw <= k:
    p = list(range(100001))
    for i in range(last):
        w, new, a, b = e[i]
        x, y = a, b
        while p[x] != x: p[x] = p[p[x]]; x = p[x]
        while p[y] != y: p[y] = p[p[y]]; y = p[y]
        if new == 0 or w < lastw:
            if x != y: p[x] = y
    for i in range(last+1, m):
        w, new, a, b = e[i]
        if new == 0 and w <= k:
            x, y = a, b
            while p[x] != x: p[x] = p[p[x]]; x = p[x]
            while p[y] != y: p[y] = p[p[y]]; y = p[y]
            if x != y:
                ans -= 1
                break

print(ans)
