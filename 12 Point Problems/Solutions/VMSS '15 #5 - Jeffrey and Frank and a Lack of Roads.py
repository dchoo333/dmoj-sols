import sys
D = sys.stdin.buffer.read().split()
n, M, U = int(D[0]), int(D[1]), int(D[2])
E = []; V = []; A = []; B = []
for i in range(n):
    E.append(D[3 + 4 * i].decode())
    V.append(int(D[4 + 4 * i])); A.append(int(D[5 + 4 * i])); B.append(int(D[6 + 4 * i]))

dp = [[0] * (U + 1) for _ in range(M + 1)]
w = [[-1] * (U + 1) for _ in range(M + 1)]

for i in range(n):
    v, a, b = V[i], A[i], B[i]
    for c in range(a, M + 1):
        r = dp[c]; p = dp[c - a]; q = w[c]
        for u in range(b, U + 1):
            x = p[u - b] + v
            if x > r[u]: r[u] = x; q[u] = i

k = [0] * n
c, u = M, U
while w[c][u] != -1:
    i = w[c][u]
    k[i] += 1; c -= A[i]; u -= B[i]

o = [str(dp[M][U])]
for i in range(n): o.append(E[i] + " " + str(k[i]))
print("\n".join(o))