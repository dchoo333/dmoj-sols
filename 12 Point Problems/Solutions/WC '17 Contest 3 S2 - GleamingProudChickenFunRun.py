import sys
from bisect import bisect_left
D = sys.stdin.buffer.read().split()
n = int(D[0])
I = sorted(zip(map(int, D[1:1 + 2 * n:2]), map(int, D[2:2 + 2 * n:2])))
A = [a for a, b in I]

pm = [0] * n
m = -1
for i in range(n):
    if I[i][1] > m: m = I[i][1]
    pm[i] = m

sm = [0] * (n + 1)
sm[n] = 1 << 62
for i in range(n - 1, -1, -1): sm[i] = min(sm[i + 1], I[i][1])

M = -1; c = 0
while True:
    i = bisect_left(A, M)
    if i == n: break
    bu = sm[i]
    M = pm[bisect_left(A, bu) - 1]
    c += 1

print(c)