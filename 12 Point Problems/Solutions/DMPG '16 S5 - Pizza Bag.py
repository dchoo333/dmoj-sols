from collections import deque
n,k=map(int,input().split())
a=list(map(int,input().split()))*2
p=[0]*(2*n+1)
for i in range(2*n):p[i+1]=p[i]+a[i]
q=deque([0]);b=-10**18
for j in range(1,2*n+1):
    while q[0]<j-k:q.popleft()
    b=max(b,p[j]-p[q[0]])
    while q and p[q[-1]]>=p[j]:q.pop()
    q.append(j)
print(b)