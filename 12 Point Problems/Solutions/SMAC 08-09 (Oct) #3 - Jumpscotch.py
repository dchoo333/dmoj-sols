import sys
from collections import deque
from itertools import islice
f = sys.stdin.buffer
n, d = map(int, f.readline().split())
it = map(int, islice(f, n))
v = next(it)

if d <= 50:
    w = deque([v], maxlen=d)
    for x in it:
        v = min(w) + x
        w.append(v)
else:
    qv = deque([v]); qi = deque([0])
    for i, x in enumerate(it, 1):
        if qi[0] < i - d: qi.popleft(); qv.popleft()
        v = qv[0] + x
        while qv and qv[-1] >= v: qv.pop(); qi.pop()
        qv.append(v); qi.append(i)

print(v)