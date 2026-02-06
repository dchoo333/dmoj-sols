f = int(input())
r = int(input())
c = int(input())

b = [list(input()) for _ in range(r)]
v = [[0]*c for _ in range(r)]
sz = []

for i in range(r):
    for j in range(c):
        if b[i][j] == '.' and not v[i][j]:
            q = [(i, j)]
            v[i][j] = 1
            s = 1

            while q:
                x, y = q.pop()
                for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < r and 0 <= ny < c and b[nx][ny] == '.' and not v[nx][ny]:
                        v[nx][ny] = 1
                        q.append((nx, ny))
                        s += 1

            sz.append(s)

sz.sort(reverse=True)

rm = 0
for x in sz:
    if f >= x:
        f -= x
        rm += 1
    else:
        break

if rm == 1:
    print(f"{rm} room, {f} square metre(s) left over")
else:
    print(f"{rm} rooms, {f} square metre(s) left over")
