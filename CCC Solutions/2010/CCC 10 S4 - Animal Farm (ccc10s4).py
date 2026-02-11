n = int(input())
g = [[] for _ in range(n+1)]
e = []
m = {}

for p in range(1, n+1):
    d = list(map(int, input().split()))
    c = d[0]
    v = d[1:c+1]
    w = d[c+1:]
    for i in range(c):
        x, y = sorted((v[i], v[(i+1)%c]))
        z = w[i]
        e.append((x, y, z))
        m.setdefault((x, y, z), []).append(p)

te = []
oe = []

for x, y, z in e:
    pns = m[(x, y, z)]
    if len(pns) == 1:
        g[0].append((pns[0], z))
        g[pns[0]].append((0, z))
        oe.append((0, pns[0], z))
    else:
        a, b = pns[0], pns[1]
        g[a].append((b, z))
        g[b].append((a, z))
        te.append((a, b, z))

par = list(range(n+1))

te.sort(key=lambda x: x[2])
a1 = 0
cnt = 0

for x, y, z in te:
    i = x
    while par[i] != i:
        i = par[i]
    j = y
    while par[j] != j:
        j = par[j]
    if i != j:
        par[i] = j
        a1 += z
        cnt += 1

if cnt != n-1:
    a1 = float('inf')

par = list(range(n+1))
ae = sorted(te + oe, key=lambda x: x[2])
a2 = 0
cnt = 0

for x, y, z in ae:
    i = x
    while par[i] != i:
        i = par[i]
    j = y
    while par[j] != j:
        j = par[j]
    if i != j:
        par[i] = j
        a2 += z
        cnt += 1

print(min(a1, a2))
