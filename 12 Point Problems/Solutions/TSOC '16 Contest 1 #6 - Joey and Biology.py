n, m = map(int, input().split())
a = input().strip()
b = input().strip()
B = 10 ** 9

P1 = [(j + 2) // 3 for j in range(m + 1)]
P2 = [B] * (m + 1)
P3 = [B] * (m + 1)

for i in range(1, n + 1):
    c = a[i - 1]
    V = [min(x, y, z) + 1 for x, y, z in zip(P1, P2, P3)]
    G = [p + (c != q) for p, q in zip(P1, b)]
    x1 = (i + 2) // 3; x2 = x3 = B
    cur = [x1]
    for d, v in zip(G, V[1:]):
        if v < d: d = v
        h = min(x1, x2, x3) + 1
        if h < d: d = h
        cur.append(d)
        x3, x2, x1 = x2, x1, d
    P1, P2, P3 = cur, P1, P2

print(P1[m])