import sys
d=sys.stdin.buffer.read().split()
n,q=int(d[0]),int(d[1])
a=list(map(int,d[2:2+n]))
p=[0]*(n+1)
for i in range(n):p[i+1]=p[i]+a[i]
qs=[]
k=2+n
for i in range(q):
    qs.append((int(d[k+2]),int(d[k]),int(d[k+1]),i));k+=3
qs.sort()
o=sorted(range(n),key=lambda i:a[i])
f=[0]*(n+1)
r=[0]*q
j=0
for kk,l,rr,i in qs:
    while j<n and a[o[j]]<kk:
        x=o[j]+1;v=a[o[j]]
        while x<=n:f[x]+=v;x+=x&-x
        j+=1
    s=0;x=rr
    while x:s+=f[x];x-=x&-x
    x=l-1
    while x:s-=f[x];x-=x&-x
    r[i]=p[rr]-p[l-1]-2*s
sys.stdout.write("\n".join(map(str,r))+"\n")
