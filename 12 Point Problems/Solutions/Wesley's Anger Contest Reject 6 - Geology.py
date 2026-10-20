import sys
from math import gcd
D = sys.stdin.buffer.read().split()
n = int(D[0]); A = D[1:1 + n]
m = int(D[1 + n]); B = D[2 + n:2 + n + m]
P = 998244353
L = n * m // gcd(n, m)
a, b = L // n, L // m

I = []; K = []; W = []
i = k = 0; p = 0
while i < n and k < m:
    e = min((i + 1) * a, (k + 1) * b)
    I.append(i); K.append(k); W.append(e - p)
    p = e
    if e == (i + 1) * a: i += 1
    if e == (k + 1) * b: k += 1

z = len(I)
s = 0
for t in range(z):
    ra = A[I[t]]; rb = B[K[t]]
    r = 0
    for u in range(z):
        if ra[I[u]] == rb[K[u]]: r += W[u]
    s += W[t] * r

print(s % P * pow(L * L % P, P - 2, P) % P)