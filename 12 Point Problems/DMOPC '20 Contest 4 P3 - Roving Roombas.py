import sys
from bisect import bisect_left
d=sys.stdin.buffer.read().split()
n,m=int(d[0]),int(d[1])
r=sorted((int(d[2+2*i]),int(d[3+2*i])) for i in range(n))
k=2+2*n
c=sorted((int(d[k+2*i]),int(d[k+2*i+1])) for i in range(m))
ys=sorted(y for _,y in c)
f=[0]*(m+1)
j=0;a=0;t=0
for x,y in r:
    while j<m and c[j][0]<=x:
        p=bisect_left(ys,c[j][1])+1
        while p<=m:f[p]+=1;p+=p&-p
        j+=1;t+=1
    p=bisect_left(ys,y);s=0
    while p:s+=f[p];p-=p&-p
    a+=t-s
print(a)