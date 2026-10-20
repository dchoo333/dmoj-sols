n=int(input())
a=[int(input()) for _ in range(n+1)]
m=max(a)
s=bytearray(m+1)
for x in a:s[x]=1
p=list(range(m+1))
for i in range(2,m+1):
    if p[i]==i:
        for j in range(i,m+1,i):p[j]-=p[j]//i
r=0
for d in range(2,m+1):
    if any(s[d::d]):r+=p[d]
print(r)