import sys
D = sys.stdin.buffer.read().split()
n, m = int(D[0]), int(D[1])
f = list(map(int, D[2:2 + n]))

s = [0] * n
r = [-1] * n
c = [-1] * n
k = 0

for i in range(n):
    if s[i]: continue
    p = []
    u = i
    while not s[u]:
        s[u] = 1; p.append(u); u = f[u]
    if s[u] == 1:
        v = u
        while True:
            r[v] = v; c[v] = k; v = f[v]
            if v == u: break
        k += 1
    for v in reversed(p):
        if r[v] == -1: r[v] = r[f[v]]
        s[v] = 2

o = []
for q in range(m):
    a, b = r[int(D[2 + n + 2 * q])], r[int(D[3 + n + 2 * q])]
    o.append(0 if c[a] != c[b] else 1 if a == b else 2)

print("\n".join(map(str, o)))