from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    g = [list(int(input()) for _ in range(n)) for __ in range(n)]
    d = g[0][0]
    b = [[-1]*n for _ in range(n)]
    bid = 0

    for y in range(n):
        for x in range(n):
            if b[y][x] != -1:
                continue
            stack = [(y, x)]
            while stack:
                cy, cx = stack.pop()
                if b[cy][cx] != -1:
                    continue
                b[cy][cx] = bid
                for ny, nx in [(cy-1,cx),(cy+1,cx),(cy,cx-1),(cy,cx+1)]:
                    if 0<=ny<n and 0<=nx<n and abs(g[cy][cx]-g[ny][nx])<=2 and b[ny][nx]==-1 and (g[ny][nx]>d)==(g[cy][cx]>d):
                        stack.append((ny,nx))
            bid += 1

    q = deque([(0,0)])
    mo = [[-1]*n for _ in range(n)]
    mo[0][0] = 0

    while q:
        y, x = q.popleft()
        v = mo[y][x]

        if g[y][x] <= d:
            stack = [(y, x)]
            while stack:
                cy, cx = stack.pop()
                if mo[cy][cx] != -1 and mo[cy][cx] < v:
                    continue
                mo[cy][cx] = v
                for ny, nx in [(cy-1,cx),(cy+1,cx),(cy,cx-1),(cy,cx+1)]:
                    if 0<=ny<n and 0<=nx<n and abs(g[cy][cx]-g[ny][nx])<=2 and mo[ny][nx]==-1:
                        if b[ny][nx]==b[cy][cx]:
                            mo[ny][nx] = v
                            stack.append((ny,nx))
                        else:
                            mo[ny][nx] = v+1
                            q.append((ny,nx))
        else:
            for ny, nx in [(y-1,x),(y+1,x),(y,x-1),(y,x+1)]:
                if 0<=ny<n and 0<=nx<n and abs(g[ny][nx]-g[y][x])<=2 and mo[ny][nx]==-1:
                    mo[ny][nx] = v+1
                    q.append((ny,nx))

    print(mo[-1][-1] if mo[-1][-1]>=0 else 'CANNOT MAKE THE TRIP')
    if _ != t-1:
        print()
