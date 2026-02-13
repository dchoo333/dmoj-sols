from collections import deque

n,m = map(int,input().split())
g = []
cams = []
convs = []

for i in range(n):
    line = input().strip()
    g.append(line)
    for j,c in enumerate(line):
        if c=='S': s=(i,j)
        elif c=='C': cams.append((i,j))
        elif c in 'LRUD': convs.append((c,i,j))

q = deque([s])
vis = [[-1]*m for _ in range(n)]
vis[s[0]][s[1]] = 0
cnt = 1
camd = [[0]*m for _ in range(n)]

for cx,cy in cams:
    camd[cx][cy] = 1
    for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
        nx,ny = cx+dx, cy+dy
        while 0<=nx<n and 0<=ny<m:
            if g[nx][ny]=='W': break
            if g[nx][ny] in '.S': camd[nx][ny]=1
            nx+=dx; ny+=dy

key = {'L':(0,-1),'R':(0,1),'U':(-1,0),'D':(1,0)}

def func(x,y,dx,dy,seen):
    seen.add((x,y))
    nx,ny=x+dx,y+dy
    if not (0<=nx<n and 0<=ny<m) or g[nx][ny] in 'WC': return -1
    if g[nx][ny] in 'LRUD':
        if (nx,ny) in seen: return -1
        return func(nx,ny,*key[g[nx][ny]],seen)
    if g[nx][ny] in '.S': return (nx,ny)

while q:
    for _ in range(len(q)):
        x,y=q.popleft()
        if camd[x][y]: continue
        for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx,ny=x+dx,y+dy
            if not (0<=nx<n and 0<=ny<m): continue
            if vis[nx][ny]==-1:
                if g[nx][ny]=='.' and camd[nx][ny]==0:
                    vis[nx][ny]=cnt
                    q.append((nx,ny))
                elif g[nx][ny] in 'LRUD':
                    new=func(nx,ny,*key[g[nx][ny]],set())
                    if new!=-1 and vis[new[0]][new[1]]==-1 and camd[new[0]][new[1]]==0:
                        vis[new[0]][new[1]]=cnt
                        q.append(new)
    cnt+=1

for i in range(n):
    for j in range(m):
        if g[i][j]=='.':
            print(vis[i][j])
