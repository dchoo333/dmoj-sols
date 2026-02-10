while True:
    n = int(input())
    if n == 0:
        break

    g = [list(map(int, input().split())) for _ in range(n)]

    idn = -1
    for i in range(n):
        if all(g[i][j] == j+1 and g[j][i] == j+1 for j in range(n)):
            idn = i + 1
            break

    if idn == -1:
        print("no")
        continue

    inv = True
    for i in range(n):
        found = False
        for j in range(n):
            if g[i][j] == idn:
                found = True
                if g[j][i] != idn:
                    inv = False
        if not found:
            inv = False
    if not inv:
        print("no")
        continue

    assoc = True
    for x in range(n):
        for y in range(n):
            for z in range(n):
                if g[x][g[y][z]-1] != g[g[x][y]-1][z]:
                    assoc = False
                    break
            if not assoc:
                break
        if not assoc:
            break

    print("yes" if assoc else "no")
