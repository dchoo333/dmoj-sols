import sys
from bisect import bisect_left, bisect_right

a = list(map(int, sys.stdin.read().split()))

d = []
for x in a:
    i = bisect_right(d, -x)
    if i == len(d): d.append(-x)
    else: d[i] = -x

e = []
for x in a:
    i = bisect_left(e, x)
    if i == len(e): e.append(x)
    else: e[i] = x

print(len(d))
print(len(e))