a, b, c, d = map(int, input().split())
g = [[0] * 5 for _ in range(5)]
g[0][0] = 0
g[0][1] = a
g[0][2] = a + b
g[0][3] = g[0][2] + c
g[0][4] = g[0][3] + d
g[1][0] = a
g[2][0] = a + b
g[3][0] = g[2][0] + c
g[4][0] = g[3][0] + d
for i in range(1, 5):
    for j in range(1, 5):
        g[i][j] = abs(g[i][0] - g[0][j])
for i in range(5):
    for j in range(5):
        print(g[i][j], end=" ")
    print()
