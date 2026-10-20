import heapq
n=int(input())
t=list(map(int,input().split()))
s=list(range(n+1))
for i in range(2,int(n**.5)+1):
    if s[i]==i:
        for j in range(i*i,n+1,i):
            if s[j]==j:s[j]=i
l=[0]*(n+1);g=[[] for _ in range(n+1)];d=[0]*(n+1)
for x in t:
    y=x
    while y>1:
        p=s[y]
        while y%p==0:y//=p
        if l[p]:g[l[p]].append(x);d[x]+=1
        l[p]=x
h=[-x for x in t if d[x]==0]
heapq.heapify(h)
o=[]
while h:
    x=-heapq.heappop(h);o.append(x)
    for y in g[x]:
        d[y]-=1
        if d[y]==0:heapq.heappush(h,-y)
print(*o)