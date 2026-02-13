w = input()
n, m = [int(input()) for _ in range(2)]
b, p = [], []

for i in range(n):
    r = input().split()
    for j in range(m):
        if r[j] == w[0]:
            p.append((i, j))
    b.append(r)

ans = 0
stack = []

for r0, c0 in p:
    for dx in range(-1, 2):
        for dy in range(-1, 2):
            if dx == 0 and dy == 0:
                continue
            stack.append((r0, c0, (dx, dy), 1, True))
            while stack:
                r, c, d, i, s = stack.pop()
                if i == len(w):
                    ans += 1
                    continue
                r1, c1 = r + d[0], c + d[1]
                if 0 <= r1 < n and 0 <= c1 < m and b[r1][c1] == w[i]:
                    stack.append((r1, c1, d, i + 1, s))
                if s and i != 1:
                    for d2 in [(d[1], -d[0]), (-d[1], d[0])]:
                        r2, c2 = r + d2[0], c + d2[1]
                        if 0 <= r2 < n and 0 <= c2 < m and b[r2][c2] == w[i]:
                            stack.append((r2, c2, d2, i + 1, False))

print(ans)
