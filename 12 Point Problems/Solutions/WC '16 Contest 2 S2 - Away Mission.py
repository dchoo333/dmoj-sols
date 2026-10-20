import sys
D = sys.stdin.buffer.read().split()
n, q = int(D[0]), int(D[1])
R = sorted(map(int, D[2:2 + n]))
G = sorted(map(int, D[2 + n:2 + 2 * n]))
B = sorted(map(int, D[2 + 2 * n:2 + 3 * n]))

if q == 1:
    P = sorted(G + B)
    i = k = 0
    for p in P:
        if i < n and R[i] <= p: i += 1; k += 1
    print(n - k)
else:
    def ok(k):
        M = [max(G[i], B[i]) for i in range(k)]
        for i in range(k):
            if R[n - 1 - i] <= M[k - 1 - i]: return False
        return True
    lo, hi = 0, n
    while lo < hi:
        md = (lo + hi + 1) // 2
        if ok(md): lo = md
        else: hi = md - 1
    print(lo)