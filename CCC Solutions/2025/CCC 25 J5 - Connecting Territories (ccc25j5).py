r,c,m=[int(input())for _ in range(3)]
p=[i%m+1 for i in range(c)]
for i in range(1,r):
    b=i*c
    q=[0]*c
    g=b%m+1
    q[0]=min(p[0],p[1])+g
    for j in range(1,c-1):
        g=(b+j)%m+1
        a=p[j-1]
        b0=p[j]
        c0=p[j+1]
        if a<b0:
            if a<c0:q[j]=a+g
            else:q[j]=c0+g
        else:
            if b0<c0:q[j]=b0+g
            else:q[j]=c0+g
    g=(b+c-1)%m+1
    q[-1]=min(p[-2],p[-1])+g
    p=q
print(min(p))
