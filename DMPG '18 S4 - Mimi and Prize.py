n=int(input())
a=list(map(int,input().split()))
p=list(range(n))
def f(x):
    while p[x]!=x:p[x]=p[p[x]];x=p[x]
    return x
for _ in range(n-1):
    u,v=map(int,input().split())
    u-=1;v-=1
    if (a[u]^a[v])&1:
        x=f(u);y=f(v)
        if x!=y:p[x]=y
s=[0]*n;o=[0]*n
for i in range(n):
    r=f(i);s[r]+=1;o[r]+=a[i]&1
print(sum(o[i]*s[i] for i in range(n)))