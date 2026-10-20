for t in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    r = n * n - 1 - k
    o = []
    if r % 2 == 0:
        s, a, cp = n, 1, 0
        while r > 0 and s >= 3:
            nx = None
            for j in range(4):
                sv = 4 * s - 6 - 2 * j
                if sv <= 0: break
                if sv > r: continue
                p = max(cp, j * (s - 1) + 1)
                if p > (j + 1) * (s - 1) - 1: continue
                q = j * (s - 3) + (p - j * (s - 1)) - 1
                o.append(f"{a + p} {a + 4 * (s - 1) + q}")
                r -= sv
                nx = q
                break
            a += 4 * (s - 1)
            s -= 2
            cp = nx if nx is not None else 0

    if r != 0 or not o: print(f"Case #{t}: IMPOSSIBLE")
    else: print(f"Case #{t}: {len(o)}\n" + "\n".join(o))