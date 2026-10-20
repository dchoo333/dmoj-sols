import sys
sys.setrecursionlimit(10000)

def mv(p, i):
    p = list(p)
    h = p[i]; p[i] = 0
    a = b = 0
    j = i
    while h:
        j = (j + 1) % 7
        if h > 1:
            if p[j] == 5: p[j] -= 1; a += 1
            else: p[j] += 1; h -= 1
        else:
            if 1 <= p[j] <= 4: a += p[j] + 1; p[j] = 0
            else: b += 1
            h = 0
    return tuple(p), a - b

memo = {}
def g(p):
    if not any(p): return 0
    if p in memo: return memo[p]
    best = -100
    for i in range(7):
        if p[i]:
            q, d = mv(p, i)
            best = max(best, d - g(q))
    memo[p] = best
    return best

p = tuple(map(int, input().split()))
while True:
    bi, bv = -1, -100
    for i in range(7):
        if p[i]:
            q, d = mv(p, i)
            v = d - g(q)
            if v > bv: bv, bi = v, i
    print(bi + 1, flush=True)
    p, _ = mv(p, bi)
    if not any(p): break
    o = int(input())
    p, _ = mv(p, o - 1)
    if not any(p): break