for t in range(1, int(input()) + 1):
    n = int(input())
    f = [0] + list(map(int, input().split()))
    p = [0] + list(map(int, input().split()))

    mn = [0] * (n + 1)
    sm = [0] * (n + 1)
    r = 0
    for i in range(n, 0, -1):
        v = max(f[i], mn[i]) if mn[i] else f[i]
        r += sm[i] - mn[i]
        q = p[i]
        if q:
            sm[q] += v
            if not mn[q] or v < mn[q]: mn[q] = v
        else:
            r += v
    print(f"Case #{t}: {r}")