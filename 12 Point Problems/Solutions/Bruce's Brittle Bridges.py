n=int(input())
v=[0]+list(map(int,input().split()))
g=[[] for _ in range(n+1)]
for _ in range(n-1):
    a,b,t=map(int,input().split())
    g[a].append((b,t))
    g[b].append((a,t))
p=[0]*(n+1)
r=[0]*(n+1)
e=[0]*(n+1)
q=[False]*(n+1)
o=[]
s=[1]
q[1]=True
while s:
    x=s.pop()
    o.append(x)
    for y,t in g[x]:
        if not q[y]:
            q[y]=True
            p[y]=x
            s.append(y)
for x in reversed(o):
    b=v[x]
    d=0
    for y,t in g[x]:
        if y!=p[x]:
            if t>1:
                b+=r[y]
                if e[y]-r[y]>d:d=e[y]-r[y]
            elif e[y]>d:d=e[y]
    r[x]=b
    e[x]=b+d
print(e[1])