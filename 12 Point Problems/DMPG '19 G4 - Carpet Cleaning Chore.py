m,n=map(int,input().split())
g=[[1 if ch=='D' else 0 for ch in input()[:n]]+[0] for _ in range(m)]+[[0]*(n+1)]
d=[bytearray(n) for _ in range(m)];c=0
for i in range(m):
    r=g[i];s=g[i+1];e=d[i]
    for j in range(n):
        v=r[j]^r[j+1]^s[j]^s[j+1];e[j]=v;c+=v
q=int(input());o=[]
for _ in range(q):
    a,b=map(int,input().split())
    for i in(a-1,a-2):
        if i>=0:
            e=d[i]
            for j in(b-1,b-2):
                if j>=0:
                    e[j]^=1;c+=1 if e[j] else -1
    o.append(c)
print("\n".join(map(str,o)))