g = [list(map(int, input().split())) for _ in range(4)]

rows = [sum(r) for r in g]
cols = [sum(g[i][j] for i in range(4)) for j in range(4)]

if len(set(rows + cols)) == 1:
    print("magic")
else:
    print("not magic")
