import sys
n, q1, q2, s = map(int, input().split())

def c(i, j):
    print("c", i, j, flush=True)
    r = int(input())
    if r == -1: sys.exit()
    return r == i

k = min(n, q2)
v = []
for i in range(1, k + 1):
    print("h", i, flush=True)
    r = int(input())
    if r == -1: sys.exit()
    v.append((r, i))
v.sort()
a = [i for _, i in v]

for i in range(k + 1, n + 1):
    lo, hi = 0, len(a)
    while lo < hi:
        m = (lo + hi) // 2
        if c(i, a[m]): lo = m + 1
        else: hi = m
    a.insert(lo, i)

h = [0] * (n + 1)
for r, i in enumerate(a): h[i] = r + 1
print("!", *h[1:], flush=True)