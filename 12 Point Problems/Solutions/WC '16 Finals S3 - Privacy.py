import sys
sys.setrecursionlimit(10000)
D = sys.stdin.buffer.read().split()
n, k = int(D[0]), int(D[1])
c = [int(x) for x in D[2:2 + n]]

W = [[0] * (n + 1) for _ in range(n + 1)]
for l in range(n):
    f = [0] * (n + 1)
    t = 0; le = 0; s = 0
    f[c[l]] += 1
    if c[l] <= 0: le += 1
    Wl = W[l]
    for r in range(l + 1, n):
        t += 1
        s += le
        le += f[t]
        if c[r] < t: s += t - c[r]
        f[c[r]] += 1
        if c[r] <= t: le += 1
        Wl[r + 1] = s

I = 1 << 60

def go(lo, hi, ol, oh):
    if lo > hi: return
    md = (lo + hi) >> 1
    b = I; bo = ol
    for l in range(ol, min(md - 1, oh) + 1):
        v = dp[l] + W[l][md]
        if v < b: b = v; bo = l
    nd[md] = b
    go(lo, md - 1, ol, bo)
    go(md + 1, hi, bo, oh)

dp = [I] * (n + 1); dp[0] = 0
for _ in range(min(k + 1, n)):
    nd = [I] * (n + 1); nd[0] = I
    go(1, n, 0, n - 1)
    dp = nd
    if dp[n] == 0: break

print(dp[n])