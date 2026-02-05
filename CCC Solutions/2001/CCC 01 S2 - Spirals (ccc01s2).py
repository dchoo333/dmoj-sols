g = [[0]*10 for _ in range(10)]
r = c = 4

s, e = [int(input()) for _ in range(2)]

if s == e:
    print(s)
else:
    g[4][4] = s
    x = s
    k = 1
    mode = 0

    while True:
        if mode == 0:
            for _ in range(k):
                r += 1
                x += 1
                g[r][c] = x
                if x == e: break
            if x == e: break
            for _ in range(k):
                c += 1
                x += 1
                g[r][c] = x
                if x == e: break
            if x == e: break
            k += 1
            mode = 1
        else:
            for _ in range(k):
                r -= 1
                x += 1
                g[r][c] = x
                if x == e: break
            if x == e: break
            for _ in range(k):
                c -= 1
                x += 1
                g[r][c] = x
                if x == e: break
            if x == e: break
            k += 1
            mode = 0

    for i in range(10):
        for j in range(10):
            print(f"{g[i][j]:3}" if g[i][j] else "   ", end="")
        print()
