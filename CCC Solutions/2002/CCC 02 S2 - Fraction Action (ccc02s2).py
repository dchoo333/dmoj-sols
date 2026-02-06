from math import gcd

n = int(input())
d = int(input())

if n == 0:
    print(0)
else:
    w, r = divmod(n, d)
    if r == 0:
        print(w)
    else:
        g = gcd(r, d)
        r //= g
        d //= g
        print(f"{w} {r}/{d}" if w else f"{r}/{d}")
