import sys
from collections import deque
D = sys.stdin.buffer.read().split()
H, J, n = int(D[0]), int(D[1]), int(D[2])
bad = bytearray(H + 1)
for i in range(n):
    a, b = int(D[3 + 2 * i]), int(D[4 + 2 * i])
    bad[a:b + 1] = b'\x01' * (b - a + 1)

d = [-1] * H
d[0] = 0
q = deque([0])
t = 0
a = -1

while q:
    h = q.popleft(); x = d[h]
    v = h + J
    if v >= H: a = x + 1; break
    if not bad[v] and d[v] < 0: d[v] = x + 1; q.append(v)
    if h > t:
        for v in range(t, h):
            if not bad[v] and d[v] < 0: d[v] = x + 1; q.append(v)
        t = h

print(a)