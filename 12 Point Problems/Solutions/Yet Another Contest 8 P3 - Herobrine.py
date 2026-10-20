n = int(input())
P = [0] + list(map(int, input().split()))
M = [0] * (n + 1)
ores = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    row = list(map(int, input().split()))
    M[i] = row[0]
    ores[i] = row[1:]

ch = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    ch[P[i]].append(i)

w = M[:]
for i in range(n, 0, -1):
    w[P[i]] += w[i]

heavy = [-1] * (n + 1)
for v in range(n + 1):
    b = -1
    for c in ch[v]:
        if w[c] > b:
            b = w[c]
            heavy[v] = c

flat = []
start = [0] * (n + 1)
stack = [0]
while stack:
    v = stack.pop()
    start[v] = len(flat)
    flat.extend(ores[v])
    h = heavy[v]
    for c in ch[v]:
        if c != h:
            stack.append(c)
    if h != -1:
        stack.append(h)

cnt = [0] * (10**6 + 1)
f = [0] * (len(flat) + 2)
ans = [0] * (n + 1)

for v in range(n + 1):
    if v and heavy[P[v]] == v:
        continue
    path = []
    u = v
    while u != -1:
        path.append(u)
        u = heavy[u]
    best = 0
    for u in reversed(path):
        s = start[u]
        h = heavy[u]
        seg = flat[s:s + M[u]]
        if h != -1:
            seg += flat[s + M[u] + w[h]:s + w[u]]
        for t in seg:
            c = cnt[t] + 1
            cnt[t] = c
            x = f[c] + 1
            f[c] = x
            if c * x > best:
                best = c * x
        ans[u] = best
    for t in flat[start[v]:start[v] + w[v]]:
        cnt[t] = 0
    f[1:w[v] + 1] = [0] * w[v]

print("\n".join(map(str, ans[1:])))