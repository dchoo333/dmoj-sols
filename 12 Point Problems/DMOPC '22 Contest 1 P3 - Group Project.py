from math import isqrt
n,m,q=map(int,input().split())
d=[0]*(n+1);s=[0]*(n+1);t=[0]*(n+1);E=set();K=n+1
for _ in range(m):
    u,v=map(int,input().split())
    if u>v:u,v=v,u
    k=u*K+v
    if k in E:continue
    E.add(k);d[u]+=1;d[v]+=1;s[u]+=v;s[v]+=u;t[u]+=v*v;t[v]+=u*u
b=sum(1 for e in E if d[e//K]>1 and d[e%K]>1)
def nb(x):
    if d[x]==1:return(s[x],)
    r=isqrt(2*t[x]-s[x]*s[x]);return((s[x]+r)//2,(s[x]-r)//2)
def c(A):
    r=0
    for e in A:
        if e in E and d[e//K]>1 and d[e%K]>1:r+=1
    return r
o=["YES" if b else "NO"]
for _ in range(q):
    u,v=map(int,input().split())
    if u>v:u,v=v,u
    k=u*K+v;a=k not in E;A={k}
    for x in(u,v):
        if(a and d[x]==1)or(not a and d[x]<=2):
            for w in nb(x):A.add(min(x,w)*K+max(x,w))
    b-=c(A)
    if a:E.add(k);g=1
    else:E.discard(k);g=-1
    d[u]+=g;d[v]+=g;s[u]+=g*v;s[v]+=g*u;t[u]+=g*v*v;t[v]+=g*u*u
    b+=c(A)
    o.append("YES" if b else "NO")
print("\n".join(o))