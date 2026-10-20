import sys
from math import sqrt
D = sys.stdin.buffer.read().split()
n, S = int(D[0]), int(D[1])
X = []; Y = []; U = []; V = []
for i in range(n):
    X.append(int(D[2 + 4 * i])); Y.append(int(D[3 + 4 * i]))
    U.append(int(D[4 + 4 * i])); V.append(int(D[5 + 4 * i]))
S2 = S * S

def go(px, py, t, j):
    dx = X[j] + U[j] * t - px
    dy = Y[j] + V[j] * t - py
    a = U[j] * U[j] + V[j] * V[j] - S2
    b = 2 * (dx * U[j] + dy * V[j])
    c = dx * dx + dy * dy
    return (-b - sqrt(b * b - 4 * a * c)) / (2 * a)

I = float('inf')
F = 1 << n
dp = [I] * (F * n)
for j in range(n): dp[(1 << j) * n + j] = go(0, 0, 0, j)

for m in range(1, F):
    b = m * n
    for i in range(n):
        t = dp[b + i]
        if t == I: continue
        px = X[i] + U[i] * t; py = Y[i] + V[i] * t
        for j in range(n):
            if m >> j & 1: continue
            k = (m | 1 << j) * n + j
            nt = t + go(px, py, t, j)
            if nt < dp[k]: dp[k] = nt

print("%.10f" % min(dp[(F - 1) * n:]))