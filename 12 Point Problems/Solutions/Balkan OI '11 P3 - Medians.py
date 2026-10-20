n=int(input())
b=list(map(int,input().split()))
m=2*n-1
u=[0]*(m+2)
a=[b[0]]
u[b[0]]=1
l=1
h=m
for i in range(1,n):
    p=b[i-1]
    t=b[i]
    if t==p:
        while u[l]:l+=1
        u[l]=1
        a.append(l)
        while u[h]:h-=1
        u[h]=1
        a.append(h)
    elif t>p:
        k=2
        if not u[t]:
            u[t]=1
            a.append(t)
            k=1
        for _ in range(k):
            while u[h]:h-=1
            u[h]=1
            a.append(h)
    else:
        k=2
        if not u[t]:
            u[t]=1
            a.append(t)
            k=1
        for _ in range(k):
            while u[l]:l+=1
            u[l]=1
            a.append(l)
print(' '.join(map(str,a)))