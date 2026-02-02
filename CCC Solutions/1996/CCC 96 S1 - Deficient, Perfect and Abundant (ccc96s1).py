t = int(input())
for i in range(t):
    n = int(input())
    s = 0
    d = 1
    while d < n:
        if n % d == 0:
            s += d
        d += 1
    r = ("a deficient", "a perfect", "an abundant")[(s > n) * 2 + (s == n)]
    print(f"{n} is {r} number.")
