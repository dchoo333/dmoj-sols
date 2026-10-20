n,m=map(int,input().split())
e=[0]*(n+1)
for _ in range(m):
    x,y,w,h=map(int,input().split())
    a=min(x+w,n);k=(1<<min(y+h,n))-(1<<y)
    e[x]^=k;e[a]^=k
s=t=c=0
for i in range(n):
    if e[i]:
        s^=e[i];c=bin(s).count("1")
    t+=c
print(t)