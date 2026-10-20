import sys
D = sys.stdin.buffer.read().split()
t = int(D[0]); p = 1
I = float('inf')
o = []

for _ in range(t):
    n = int(D[p]); p += 1
    w = []
    for i in range(n):
        w.append([I if int(x) < 0 else int(x) for x in D[p:p + n]]); p += n
    for i in range(n): w[i][i] = I
    d = [r[:] for r in w]
    for i in range(n): d[i][i] = 0
    a = I

    for k in range(n):
        wk = w[k]
        for i in range(k):
            x = wk[i]
            if x == I: continue
            di = d[i]
            for j in range(i):
                y = wk[j]
                if y != I:
                    v = di[j] + x + y
                    if v < a: a = v
        dk = d[k]
        for i in range(n):
            a2 = d[i][k]
            if a2 == I: continue
            d[i] = [u if u <= a2 + v else a2 + v for u, v in zip(d[i], dk)]

    o.append("Infinity" if a == I else str(a))

print("\n".join(o))