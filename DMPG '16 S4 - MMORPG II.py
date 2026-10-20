M=10**9+7
n=int(input())
p=[0]+list(map(int,input().split()))
c=[[] for _ in range(n+1)]
for i in range(1,n+1):c[p[i]].append(i)
o=[0]
for v in o:o.extend(c[v])
s=[1]*(n+1)
for v in reversed(o):
    if v:s[p[v]]+=s[v]
f=d=1
for i in range(1,n+1):f=f*i%M;d=d*s[i]%M
print(f*pow(d,M-2,M)%M)