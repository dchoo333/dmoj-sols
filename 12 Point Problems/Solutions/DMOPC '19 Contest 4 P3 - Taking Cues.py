import sys
from collections import deque
d=sys.stdin.buffer.read().split()
n,M=int(d[0]),int(d[1])
I=-10**18
dp=[0]+[I]*100
k=2
for _ in range(n):
    X,Y,bp,sp=int(d[k]),int(d[k+1]),int(d[k+2]),int(d[k+3]);k+=4
    v=[dp[h]+h*sp if dp[h]>I else I for h in range(101)]
    A=[I]*101;q=deque()
    for g in range(100,-1,-1):
        while q and v[q[-1]]<=v[g]:q.pop()
        q.append(g)
        while q[0]>g+Y:q.popleft()
        if v[q[0]]>I:A[g]=v[q[0]]-g*sp
    w=[A[g]+g*bp if A[g]>I else I for g in range(101)]
    nd=[I]*101;q=deque()
    for h in range(101):
        while q and w[q[-1]]<=w[h]:q.pop()
        q.append(h)
        while q[0]<h-X:q.popleft()
        if w[q[0]]>I:nd[h]=w[q[0]]-h*bp-M*h
    dp=nd
print(max(dp))