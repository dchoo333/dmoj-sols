import sys
from array import array
d=sys.stdin.buffer.read().split()
n,m=int(d[0]),int(d[1])
g=[int(x) for x in d[2:2+n]]
W=n+1
f=array('i',[0])*(21*W)
for i in range(n):
    b=g[i]*W;x=i+1
    while x<=n:f[b+x]+=1;x+=x&-x
o=[];k=2+n
for _ in range(m):
    if d[k]==b'1':
        a=int(d[k+1]);v=int(d[k+2]);k+=3
        b=g[a-1]*W;x=a
        while x<=n:f[b+x]-=1;x+=x&-x
        g[a-1]=v;b=v*W;x=a
        while x<=n:f[b+x]+=1;x+=x&-x
    else:
        l=int(d[k+1]);r=int(d[k+2]);c=int(d[k+3]);k+=4
        for v in range(20,-1,-1):
            b=v*W;s=0;x=r
            while x:s+=f[b+x];x-=x&-x
            x=l-1
            while x:s-=f[b+x];x-=x&-x
            if s>=c:o.append(v);break
            c-=s
print("\n".join(map(str,o)))