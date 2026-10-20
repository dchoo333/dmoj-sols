n, k = map(int, input().split())
L = []; R = []
for _ in range(n):
    x, m = map(int, input().split())
    if x > 0: R.append((x, m))
    elif x < 0: L.append((-x, m))

t = 0
for side in (L, R):
    side.sort(reverse=True)
    rem = 0
    for x, m in side:
        u = min(rem, m); rem -= u; m -= u
        if m:
            tr = (m + k - 1) // k
            t += tr * 2 * x
            rem = tr * k - m
print(t)