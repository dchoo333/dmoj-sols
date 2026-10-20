import sys
D = sys.stdin.buffer.read().split()
n, q = int(D[0]), int(D[1])

p = list(range(n + 1))
u = [False] * (n + 1)
o = [0] * (n + 1)
c = 0; od = 0

def f(x):
    while p[x] != x:
        p[x] = p[p[x]]; x = p[x]
    return x

R = []
for i in range(q):
    a, b, x = int(D[2 + 3 * i]), int(D[3 + 3 * i]), int(D[4 + 3 * i])
    if not u[a]: u[a] = True; c += 1
    if not u[b]: u[b] = True; c += 1
    ra, rb = f(a), f(b)
    if ra != rb: p[ra] = rb; c -= 1
    if x & 1:
        o[a] ^= 1; od += 1 if o[a] else -1
        o[b] ^= 1; od += 1 if o[b] else -1
    R.append("YES" if c == 1 and od <= 2 else "NO")

sys.stdout.write("\n".join(R) + "\n")