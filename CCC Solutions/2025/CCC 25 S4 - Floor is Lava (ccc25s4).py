import heapq
n,m=map(int,input().split())
g=[[] for _ in range(n+1)]
e=[0]*(m+1) 
for i in range(m):
    u,v,w=map(int,input().split())
    g[u].append((v,i))
    g[v].append((u,i))
    e[i]=w

pq=[(0,1,m)] 
vis=[0]*(m+1)
best=[float('inf')]*(m+1)

while pq:
    c,a,i=heapq.heappop(pq)
    if vis[i]: continue
    vis[i]=1
    if a==n:
        print(c)
        break
    for b,j in g[a]:
        if vis[j]: continue
        nc=c+abs(e[i]-e[j])
        if nc<best[j]:
            best[j]=nc
            heapq.heappush(pq,(nc,b,j))
