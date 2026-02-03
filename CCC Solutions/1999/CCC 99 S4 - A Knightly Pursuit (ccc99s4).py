from collections import deque

dx = [2,1,-1,-2,-2,-1,1,2]
dy = [1,2,2,1,-1,-2,-2,-1]

for _ in range(int(input())):
    r,c,pR,pC,kR,kC = [int(input()) for _ in range(6)]
    cnt = [[-1]*(c+1) for _ in range(r+1)]
    vis = [[False]*(c+1) for _ in range(r+1)]
    q = deque()
    q.append((kR,kC))
    cnt[kR][kC] = 0
    vis[kR][kC] = True

    while q:
        x,y = q.popleft()
        for i in range(8):
            nx,ny = x+dx[i], y+dy[i]
            if 1 <= nx <= r and 1 <= ny <= c and not vis[nx][ny]:
                vis[nx][ny] = True
                cnt[nx][ny] = cnt[x][y]+1
                q.append((nx,ny))

    paw = [0]*(r+1)
    paw[pR+1] = 1
    for i in range(pR+2,r+1):
        paw[i] = paw[i-1]+1

    win = 1
    mv = float('inf')

    for i in range(pR,r):
        if cnt[i][pC] != -1 and cnt[i][pC] <= paw[i] and (paw[i]-cnt[i][pC])%2 == 0:
            win = 3
            mv = min(mv, paw[i])
            break

    if win != 3:
        for i in range(pR,r):
            if cnt[i+1][pC] != -1 and cnt[i+1][pC] <= paw[i] and (paw[i]-cnt[i+1][pC])%2 == 0:
                win = 2
                mv = min(mv, paw[i])
                break

    if win < 2:
        mv = paw[r]-1

    if win == 3:
        print(f"Win in {mv} knight move(s).")
    elif win == 2:
        print(f"Stalemate in {mv} knight move(s).")
    else:
        print(f"Loss in {mv} knight move(s).")
