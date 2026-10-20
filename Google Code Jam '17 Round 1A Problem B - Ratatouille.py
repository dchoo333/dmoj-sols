import sys

t = int(input())
for tc in range(1, t + 1):
    n, p = map(int, input().split())
    r = list(map(int, input().split()))
    iv = []

    for i in range(n):
        qs = sorted(map(int, input().split()))
        ls = []
        for q in qs:
            lo = (10 * q + 11 * r[i] - 1) // (11 * r[i])
            hi = (10 * q) // (9 * r[i])
            if lo <= hi:
                ls.append((lo, hi))
        iv.append(ls)

    pt = [0] * n
    k = 0
    while all(pt[i] < len(iv[i]) for i in range(n)):
        cur = [iv[i][pt[i]] for i in range(n)]
        mx = max(c[0] for c in cur)
        mn = min(c[1] for c in cur)
        if mx <= mn:
            k += 1
            for i in range(n):
                pt[i] += 1
        else:
            j = min(range(n), key=lambda i: cur[i][1])
            pt[j] += 1
    print(f"Case #{tc}: {k}")