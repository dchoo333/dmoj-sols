t = int(input())

for tc in range(t):
    s, e = map(int, input().split())

    if s == e:
        print(s)
        if tc != t-1:
            print()
        continue

    n = e - s + 3
    g = [[None]*n for _ in range(n)]

    r = c = n//2
    g[r][c] = s

    x = s
    k = 1
    m = 0

    minr = maxr = r
    minc = maxc = c

    while x < e:
        if m == 0:
            for _ in range(k):
                r += 1
                x += 1
                g[r][c] = x
                minr = min(minr, r)
                maxr = max(maxr, r)
                if x == e: break
            if x == e: break
            for _ in range(k):
                c += 1
                x += 1
                g[r][c] = x
                minc = min(minc, c)
                maxc = max(maxc, c)
                if x == e: break
            k += 1
            m = 1
        else:
            for _ in range(k):
                r -= 1
                x += 1
                g[r][c] = x
                minr = min(minr, r)
                maxr = max(maxr, r)
                if x == e: break
            if x == e: break
            for _ in range(k):
                c -= 1
                x += 1
                g[r][c] = x
                minc = min(minc, c)
                maxc = max(maxc, c)
                if x == e: break
            k += 1
            m = 0

    # CONTROL PADDING & COLUMN ALIGNMENT!!!
    cols = maxc - minc + 1
    w = [0]*cols

    for j in range(cols):
        for i in range(minr, maxr+1):
            v = g[i][minc+j]
            if v is not None:
                w[j] = max(w[j], len(str(v)))

    for i in range(minr, maxr+1):
        row = []
        for j in range(cols):
            v = g[i][minc+j]
            if v is None:
                row.append(" "*w[j])
            else:
                row.append(str(v).rjust(w[j]))
        print(" ".join(row))

    if tc != t-1:
        print()
