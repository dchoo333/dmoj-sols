import sys
D = sys.stdin.buffer.read().split()
n, e, K = int(D[0]), int(D[1]), int(D[2])
m = list(map(int, D[3:3 + n]))
I = float('inf')

d = [[I] * n for _ in range(n)]
for i in range(n): d[i][i] = 0
p = 3 + n
for _ in range(e):
    u, v, w = int(D[p]) - 1, int(D[p + 1]) - 1, int(D[p + 2]); p += 3
    if w < d[u][v]: d[u][v] = d[v][u] = w

for k in range(n):
    dk = d[k]
    for i in range(n):
        a = d[i][k]
        if a > K: continue
        d[i] = [x if x <= a + y else a + y for x, y in zip(d[i], dk)]

M = [sum(1 << j for j in range(n) if d[i][j] <= K) for i in range(n)]

T = []
for k in range((n + 15) // 16):
    t = [0] * 65536
    for x in range(1, 65536):
        j = 16 * k + (x & -x).bit_length() - 1
        t[x] = t[x & (x - 1)] + (m[j] if j < n else 0)
    T.append(t)

def W(x):
    s = 0
    for t in T:
        s += t[x & 65535]; x >>= 16
    return s

b = 0
for i in range(n):
    for j in range(i, n):
        u = M[i] | M[j]
        for k in range(j, n):
            v = W(u | M[k])
            if v > b: b = v

print(b)