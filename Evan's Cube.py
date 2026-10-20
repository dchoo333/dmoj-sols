F=[(0,0,1),(-1,0,0),(0,0,-1),(1,0,0),(0,-1,0),(0,1,0)]
U=[(1,0,0),(0,0,1),(-1,0,0),(0,0,-1),(1,0,0),(-1,0,0)]
V=[(0,-1,0),(0,-1,0),(0,-1,0),(0,-1,0),(0,0,-1),(0,0,-1)]
def rt(v,a):
    x,y,z=v
    if a==0:return(x,-z,y)
    if a==1:return(z,y,-x)
    return(-y,x,z)
s={}
for f in range(6):
    n=F[f];u=U[f];v=V[f]
    for r in range(3):
        l=input().strip()
        for c in range(3):
            p=tuple(n[t]+(c-1)*u[t]+(r-1)*v[t] for t in range(3))
            s[(p,n)]=l[c]
q=int(input())
for _ in range(q):
    o=input().split()[0]
    f=int(o[0])-1;n=F[f]
    a=[i for i in range(3) if n[i]][0];g=n[a]
    k=1 if(o[1]=='C')==(g<0)else 3
    t={}
    for (p,m),c in s.items():
        if p[a]==g:
            for _ in range(k):p=rt(p,a);m=rt(m,a)
        t[(p,m)]=c
    s=t
d={}
for (p,m),c in s.items():d.setdefault(m,set()).add(c)
print('Solved!' if all(len(v)==1 for v in d.values())else 'Boo!')