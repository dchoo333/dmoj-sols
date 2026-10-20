# PyPy3 required
import sys
r=sys.stdin.readline
n,v=map(int,r().split())
c=[0]+list(map(int,r().split()))
dp=[10**9]*10001
qs=[]
a=[0]*v
p=0

for i in range(v):
    qs.append((i,)+tuple(map(int,r().split())))
qs.sort(key=lambda x:x[2])
dp[0]=0

for i in range(1,n+1):
    for j in range(c[i],10001):
        dp[j]=min(dp[j],dp[j-c[i]]+1)
    while p<v and qs[p][2]==i:
        a[qs[p][0]]=dp[qs[p][1]]
        p+=1

for x in a:
    print(-1 if x==10**9 else x)