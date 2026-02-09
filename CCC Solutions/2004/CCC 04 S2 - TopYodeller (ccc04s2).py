n,r=map(int,input().split())
s=[0]*n
w=[1]*n
c=[0]*n

for _ in range(r):
    sc=list(map(int,input().split()))
    for i in range(n): s[i]+=sc[i]
    for i in range(n):
        rk=1
        for j in range(n):
            if i!=j and s[i]<s[j]: rk+=1
        w[i]=max(w[i],rk)
        c[i]=rk

for i in range(n):
    if c[i]==1:
        print(f"Yodeller {i+1} is the TopYodeller: score {s[i]}, worst rank {w[i]}")
