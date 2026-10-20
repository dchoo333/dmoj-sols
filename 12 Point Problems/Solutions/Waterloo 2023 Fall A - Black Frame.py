from itertools import product
c = list(map(int, input().split()))
IO = [(1, 0), (1, 1), (0, 1), (0, 0)]
c5, c6, c7 = c[4], c[5], c[6]
G = [[], []]

for sq in product(range(4), repeat=4):
    if any(sq.count(t) > c[t] for t in range(4)): continue
    k1 = sq.count(0); k3 = sq.count(2)
    p = [int(IO[sq[j]][1] != IO[sq[(j + 1) % 4]][0]) for j in range(4)]
    P = sum(p)
    A = max(P, abs(k1 - k3))
    B = min(2 * c5 + k1 - k3, 2 * c6 - k1 + k3)
    A += (A - P) & 1
    B -= (B - P) & 1
    if A > B: continue
    for e in (0, 1):
        q = sum(x != e for x in p)
        if q > c7: continue
        L = max(1, -((-(A + q)) // 4))
        R = (B + c7) // 4
        if L % 2 != e: L += 1
        if R % 2 != e: R -= 1
        if L <= R: G[e].append((L, R))

a = 0
for e in (0, 1):
    G[e].sort()
    cl = cr = None
    for l, r in G[e]:
        if cr is None or l > cr + 2:
            if cr is not None: a += (cr - cl) // 2 + 1
            cl, cr = l, r
        elif r > cr: cr = r
    if cr is not None: a += (cr - cl) // 2 + 1

print(a)