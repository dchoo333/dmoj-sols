import sys
D = sys.stdin.buffer.read().split()
n = int(D[0])
S = 2003
T = [[0] * (s + 1) for s in range(S)]

a = 0
p = 1
for _ in range(n):
    o, r, c, v = int(D[p]), int(D[p + 1]), int(D[p + 2]), int(D[p + 3]); p += 4
    s = r + c
    f = T[s]; m = s
    if o == 1:
        i = r
        while i <= m:
            f[i] += v; i += i & -i
    else:
        i = r; x = 0
        while i:
            x += f[i]; i -= i & -i
        i = r - v - 1
        while i > 0:
            x -= f[i]; i -= i & -i
        a += x

print(a % 1000000007)