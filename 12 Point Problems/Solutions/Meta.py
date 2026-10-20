import sys
d=sys.stdin.buffer.read().split()
n=int(d[0])
g=[[] for _ in range(n+1)]
for i in range(n-1):
    u=int(d[1+2*i]);v=int(d[2+2*i]);g[u].append(v);g[v].append(u)
def bfs(s,bl=0):
    p=[0]*(n+1);p[s]=-1;o=[s];dist=[0]*(n+1)
    for u in o:
        for v in g[u]:
            if v!=p[u] and v!=bl:p[v]=u;dist[v]=dist[u]+1;o.append(v)
    return o,p,dist
o,p,ds=bfs(1);a=o[-1]
o,p,ds=bfs(a);b=o[-1];D=ds[b]
pa=[b]
while pa[-1]!=a:pa.append(p[pa[-1]])
def walk(r,bl):
    o,p,_=bfs(r,bl);h=[0]*(n+1)
    for u in reversed(o):
        if p[u]>0:h[p[u]]=max(h[p[u]],h[u]+1)
    return h,p
def go(x,h,p):
    c=0
    while 1:
        c+=1
        ch=[v for v in g[x] if v!=p[x] and p[v]==x and h[v]==h[x]-1]
        if len(ch)!=1:return c
        x=ch[0]
if D%2==0:
    c=pa[D//2];h,p=walk(c,0)
    br=[v for v in g[c] if h[v]==h[c]-1]
    print(1 if len(br)!=2 else 1+go(br[0],h,p)+go(br[1],h,p))
else:
    x,y=pa[D//2],pa[D//2+1]
    h1,p1=walk(x,y);h2,p2=walk(y,x)
    print(go(x,h1,p1)+go(y,h2,p2))