import sys
d=sys.stdin.buffer.read().split()
n,q=int(d[0]),int(d[1])
p=[int(x) for x in d[2:2+n]]
c=[0]*22
for i in range(n):
    x=p[i]^i
    if x:c[x.bit_length()]+=1
o=[]
k=2+n
for _ in range(q):
    u=int(d[k])-1;v=int(d[k+1])-1;k+=2
    for i in(u,v):
        x=p[i]^i
        if x:c[x.bit_length()]-=1
    p[u],p[v]=p[v],p[u]
    for i in(u,v):
        x=p[i]^i
        if x:c[x.bit_length()]+=1
    if u==v:
        pass
    r=0
    for b in range(21,0,-1):
        if c[b]:r=1<<(b-1);break
    o.append(r)
print("\n".join(map(str,o)))