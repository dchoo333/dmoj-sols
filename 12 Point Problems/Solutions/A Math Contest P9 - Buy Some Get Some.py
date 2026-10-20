from math import isqrt

a, n, p = map(int, input().split())
a %= p; n %= p

if n == 1 % p: print(0)
elif a == 0: print(1 if n == 0 else "DNE")
elif n == 0: print("DNE")
else:
    m = isqrt(p) + 1
    t = {}
    v = n
    for j in range(m):
        t[v] = j
        v = v * a % p
    g = pow(a, m, p)
    v = 1
    ans = "DNE"
    for i in range(1, m + 1):
        v = v * g % p
        if v in t:
            ans = i * m - t[v]
            break
    print(ans)