n = int(input())
r, c = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(r)]

for _ in range(n-1):
    r2, c2 = map(int, input().split())
    b = [list(map(int, input().split())) for _ in range(r2)]
    ans = [[0]*(c*c2) for _ in range(r*r2)]
    for x in range(r):
        for y in range(c):
            v = a[x][y]
            posx, posy = x*r2, y*c2
            for x2 in range(r2):
                for y2 in range(c2):
                    ans[posx+x2][posy+y2] = b[x2][y2]*v
    r, c = r*r2, c*c2
    a = [row[:] for row in ans]

flat = [v for row in a for v in row]
print(max(flat))
print(min(flat))

rowsum = [sum(row) for row in a]
print(max(rowsum))
print(min(rowsum))

colsum = [sum(a[y][x] for y in range(r)) for x in range(c)]
print(max(colsum))
print(min(colsum))
