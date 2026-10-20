n, k = map(int, input().split())
c = list(map(int, input().split()))
h = list(map(int, input().split()))

hs = sorted(set(h))
P = []
for v in hs:
    p = [0] * (n + 1)
    s = 0
    for i in range(n):
        s += c[i] * abs(h[i] - v)
        p[i + 1] = s
    P.append(p)

INF = 1 << 62
cost = [[0] * (n + 1) for _ in range(n + 1)]
for l in range(n):
    cl = cost[l]
    for r in range(l + 1, n + 1):
        b = INF
        for p in P:
            v = p[r] - p[l]
            if v < b: b = v
        cl[r] = b

d = [0] * (n + 1)
for i in range(n): d[i + 1] = d[i] + c[i] * h[i]

for _ in range(min(k, n)):
    nd = d[:]
    for i in range(1, n + 1):
        b = nd[i]
        for p in range(i):
            v = d[p] + cost[p][i]
            if v < b: b = v
        nd[i] = b
    d = nd

print(d[n])