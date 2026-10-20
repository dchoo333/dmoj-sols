from functools import lru_cache

n = int(input())
k = int(input())
d = list(map(int, str(n)))
L = len(d)

@lru_cache(maxsize=None)
def f(i, last, run, tight, st):
    if i == L: return 1 if st else 0
    r = 0
    hi = d[i] if tight else 9
    for x in range(hi + 1):
        nt = tight and x == hi
        if not st and x == 0:
            r += f(i + 1, -1, 0, nt, False)
            continue
        nr = run + 1 if st and x == last else 1
        if nr >= k: continue
        r += f(i + 1, x, nr, nt, True)
    return r

print(n - f(0, -1, 0, True, False))