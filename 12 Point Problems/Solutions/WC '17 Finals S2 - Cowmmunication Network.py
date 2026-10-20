import sys
r = sys.stdin.buffer.readline
n, m = map(int, r().split())

E = []
for _ in range(m):
    a, b, c = r().split()
    E.append((2000000 - (int(c) + 1000000)) << 34 | int(a) << 17 | int(b))
E.sort()

p = list(range(n + 1))
K = (1 << 17) - 1

def f(x):
    while p[x] != x:
        p[x] = p[p[x]]; x = p[x]
    return x

s = 0; k = n
for e in E:
    c = 1000000 - (e >> 34); a = e >> 17 & K; b = e & K
    ra, rb = f(a), f(b)
    if ra != rb:
        p[ra] = rb; k -= 1; s += c
    elif c >= 0:
        s += c

print(s if k == 1 else "Impossible")