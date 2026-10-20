import sys
from collections import deque
D = sys.stdin.buffer.read().split()
n, t = int(D[0]), int(D[1])
if n <= 1: print(0); sys.exit()

W = n + 2
S = W * W
cs = [0] * S
for i in range(n):
    r = D[2 + i]
    b = (i + 1) * W + 1
    for j in range(n): cs[b + j] = t + 1 if r[j] == 98 else 1

I = 1 << 60
d = [I] * S
s = W + 1; e = n * W + n
d[s] = 0
qa = deque([s]); qb = deque()

while True:
    if qa and (not qb or qa[0] <= qb[0]): x = qa.popleft()
    else: x = qb.popleft()
    k, u = divmod(x, S)
    if k > d[u]: continue
    if u == e: break
    for v in (u - 1, u + 1, u - W, u + W):
        c = cs[v]
        if c:
            nk = k + c
            if nk < d[v]:
                d[v] = nk
                if c == 1: qa.append(nk * S + v)
                else: qb.append(nk * S + v)

print(d[e])