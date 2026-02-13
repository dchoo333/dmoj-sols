n,m,k = map(int,input().split())
res = [-1]*(n+1)
lst = [0]*(n+1)
res[1]=1
lst[1]=1
rem = k-n
ok = True

if n>k or (n*(n+1)//2-(n-m)*(n-m+1)//2)<k:
    ok = False

for i in range(2,n+1):
    nxt = res[i-1]+1
    if nxt > m: nxt=1
    gap = i-lst[nxt]-1
    if gap <= rem:
        res[i]=nxt
        rem -= gap
    else:
        res[i]=res[i-(rem+1)]
        rem=0
    lst[res[i]]=i

if ok:
    print(*res[1:])
else:
    print(-1)
