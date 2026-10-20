R, C = map(int, input().split())
g = [['.'] * C for _ in range(R)]

g[R - 2][C - 1] = 'E'
g[R - 1][0] = 'S'

for i in range(C - 2): 
    g[R - 2 - i][i + 1] = '#'
print("\n".join("".join(r) for r in g))