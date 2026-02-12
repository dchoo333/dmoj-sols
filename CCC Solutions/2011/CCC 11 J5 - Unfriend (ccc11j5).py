n=int(input())
p={}
inv=[]
for i in range(1,n):
    x=int(input())
    p[i]=x
    inv.append(x)
res={}
for i in range(1,n+1):
    c=1
    if i in inv:
        for j,v in enumerate(inv):
            if v==i: c*=res[j+1]
        res[i]=c+1
    else:
        res[i]=2
print(res[n]-1)
