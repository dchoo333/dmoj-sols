import sys
D = sys.stdin.buffer.read().lower().split()
n, m = int(D[0]), int(D[1])

g = [0] * 26
t = [0]
for i in range(2, n + 2):
    u = 0
    for ch in D[i]:
        x = u * 26 + ch - 97
        v = g[x]
        if not v:
            v = len(t)
            g[x] = v
            g.extend([0] * 26)
            t.append(0)
        u = v
    t[u] = 1

N = len(t)
f = [0] * N
o = [0] * N
q = [g[x] for x in range(26) if g[x]]
i = 0
while i < len(q):
    u = q[i]; i += 1
    b = u * 26; fb = f[u] * 26
    for x in range(26):
        v = g[b + x]
        if v:
            w = g[fb + x]
            f[v] = w
            o[v] = w if t[w] else o[w]
            q.append(v)
        else: g[b + x] = g[fb + x]

st = [-1] * N
R = []
for k in range(m):
    u = 0; r = 0
    for ch in D[n + 2 + k]:
        u = g[u * 26 + ch - 97]
        v = u if t[u] else o[u]
        while v and st[v] != k:
            st[v] = k; r += 1; v = o[v]
    R.append(r)

sys.stdout.write("\n".join(map(str, R)) + "\n")