n,k,T=map(int,input().split())
o=[]
for _ in range(T):
    b=list(map(int,input().split()))
    h=[]
    for i,x in enumerate(b):h.insert(x,i)
    c=[0]*(k+1);v=1
    for j in range(n):
        if j and h[j-1]<h[j]:v+=1
        c[min(v,k)]+=1
    o.append(" ".join(map(str,c[1:])))
print("\n".join(o))