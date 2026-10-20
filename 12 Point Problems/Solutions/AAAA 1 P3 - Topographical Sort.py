from math import ceil
from itertools import pairwise

t=int(input())
n=int(input())

if t==1:
    h=list(map(int,input().split()))
    while h and not h[-1]: h.pop()
    h.reverse()
    while h and not h[-1]: h.pop()
    h.reverse()

    if not h:
        print(*(0 for _ in range(n)))
    else:
        c=[0,h[0],*(b for a,b in pairwise(h) if a!=b),0]
        rm,ad=[],[]
        for i in range(1,len(c)-1):
            if c[i]>max(c[i-1],c[i+1]): rm.append(c[i])
            elif c[i] and c[i]<min(c[i-1],c[i+1]): ad.append(c[i])
        rm.sort(reverse=True); ad.sort(reverse=True)
        s=" ".join(map(str,c[1:-1]))
        isl=len(s.split(" 0 "))
        res=[isl]
        for i in range(1,n):
            while rm and rm[-1]==i: rm.pop(); isl-=1
            while ad and ad[-1]==i: ad.pop(); isl+=1
            res.append(isl)
        print(*res)
else:
    isl=list(map(int,input().split()))
    mp=ceil(n/2); mv=n-mp
    pk,vl=[],[0]*(isl[0]-1)
    for i,(a,b) in enumerate(pairwise(isl),start=1):
        if b>a: vl.extend([i]*(b-a))
        elif a>b: pk.extend([i]*(a-b))
    pk.extend([n]*isl[-1])
    if len(pk)>mp or len(vl)>mv:
        print(-1)
    else:
        res=[0]*n
        for i,h in zip(range(1,n,2),vl): res[i]=h
        for i,h in zip(range(0,n,2),pk):
            res[i]=h
            if (i and h<=res[i-1]) or (i<n-1 and h<=res[i+1]):
                print(-1)
                break
        else:
            print(*res)