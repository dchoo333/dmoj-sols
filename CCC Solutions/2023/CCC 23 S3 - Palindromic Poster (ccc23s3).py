r0, c0, r1, c1 = map(int, input().split())

rot = False
ok = True

if c1 == 0 or c1 == c0:
    r0, c0, r1, c1 = c0, r0, c1, r1
    rot = True

g = [['a'] * c0 for _ in range(r0)]

if r1 == 0:
    for i in range(r0):
        g[i][-1] = 'b'
    for i in range(c0 - c1):
        g[-1][-1 - i] = chr(ord(g[-1][-1 - i]) + 1)

elif r1 == r0:
    if (c1 % 2) != (c0 % 2):
        if c0 % 2 == 0:
            print("IMPOSSIBLE")
            ok = False
        else:
            mid = c0 // 2
            for j in range(c0):
                g[0][j] = 'b'
            for j in range(1, c1 // 2 + 1):
                g[0][mid - j] = 'a'
                g[0][mid + j] = 'a'
            g[0][mid] = 'b'
    else:
        for j in range((c0 - c1) // 2):
            g[0][j] = 'b'
            g[0][-1 - j] = 'b'

else:
    for i in range(r1, r0):
        for j in range(c1, c0):
            g[i][j] = 'b'

if ok:
    if rot:
        for row in zip(*g[::-1]):
            print("".join(row))
    else:
        for row in g:
            print("".join(row))
