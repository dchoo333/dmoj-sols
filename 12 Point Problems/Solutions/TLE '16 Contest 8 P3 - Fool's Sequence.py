import sys
D = sys.stdin.buffer.read().split()
t = int(D[0])

c = [1, 0, 1]
for L in range(3, 300): c.append(c[L - 2] + c[L - 3])

o = []
for q in range(1, t + 1):
    n = int(D[q])
    L = 1
    while n > c[L]:
        n -= c[L]; L += 1
    s = []
    while L:
        a = c[L - 3] if L >= 3 else 0
        if n <= a:
            s.append("420"); L -= 3
        else:
            s.append("69"); n -= a; L -= 2
    o.append("".join(s))

print("\n".join(o))