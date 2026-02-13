n,m = [int(input()) for _ in range(2)]
g = [ ['']*(m+2) ] + [ ['']+list(input())+[''] for _ in range(n) ]
vis = [ [0]*(m+2) for _ in range(n+2) ]

r1,c1 = [int(input()) for _ in range(2)]
r1 += 1
c1 += 1

q = [(r1,c1)]
vis[r1][c1] = 1
ans = 0

while q:
    r,c = q.pop()
    if g[r][c]=='S': ans+=1
    if g[r][c]=='M': ans+=5
    if g[r][c]=='L': ans+=10
    for dr,dc in ((-1,0),(1,0),(0,-1),(0,1)):
        nr,nc = r+dr,c+dc
        if 1<=nr<=n and 1<=nc<=m and not vis[nr][nc] and g[nr][nc]!='*':
            vis[nr][nc]=1
            q.append((nr,nc))

print(ans)
