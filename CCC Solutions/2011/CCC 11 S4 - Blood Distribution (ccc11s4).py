N = 18
g = [[0]*N for _ in range(N)]
s, t = 0, 17
for i, x in enumerate(map(int, input().split()), 1): g[0][i] = x
for i, x in enumerate(map(int, input().split()), 9): g[i][17] = x
for i in range(9,17): g[1][i] = 10**9
for i in range(10,17,2): g[2][i] = 10**9
g[3][11]=g[3][12]=g[3][15]=g[3][16]=10**9
g[4][12]=g[4][16]=10**9
g[5][13]=g[5][14]=g[5][15]=g[5][16]=10**9
g[6][14]=g[6][16]=10**9
g[7][15]=g[7][16]=10**9
g[8][16]=10**9

def dfs(g, lvl, u, f):
    if u==t: return f
    for v in range(N):
        if g[u][v]>0 and lvl[v]==lvl[u]+1:
            fl = dfs(g, lvl, v, min(f, g[u][v]))
            if fl>0:
                g[u][v]-=fl
                g[v][u]+=fl
                return fl
    return 0

res=0
while True:
    lvl=[10**9]*N; q=[s]; lvl[s]=0
    for u in q:
        for v in range(N):
            if g[u][v]>0 and lvl[v]==10**9:
                lvl[v]=lvl[u]+1
                q.append(v)
    if lvl[t]==10**9: break
    while (f:=dfs(g, lvl, s, 10**9))>0: res+=f

print(res)
