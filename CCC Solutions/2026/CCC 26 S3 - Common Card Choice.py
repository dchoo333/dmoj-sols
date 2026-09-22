import sys
from math import gcd
from itertools import combinations

input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))

if a[0]==-1:
    print(8)
    d = [
        (1,1,[3],[4]),
        (1,1,[5],[6]),
        (2,2,[9,10],[11,12]),
        (1,2,[13],[14,15]),
        (1,2,[18],[17,19]),
        (1,2,[23],[22,24]),
        (1,2,[28],[25,26]),
        (1,2,[30],[29,32])
    ]
    for x, y, z, z1 in d:
        print(x,y)
        print(*z)
        print(*z1)

else:
    if n==1:
        print("NO")
    elif n==2:
        if gcd(a[0],a[1])>1:
            print("YES")
            print("1 1")
            print("1")
            print("2")
        else:
            print("NO")
    elif n==3:
        f=0
        for s in range(1,n):
            for x in combinations(range(n),s):
                y=set(x)
                r=[i for i in range(n) if i not in y]
                for t in range(1,len(r)+1):
                    for z in combinations(r,t):
                        sa=0
                        sb=0
                        for i in x: sa+=a[i]
                        for i in z: sb+=a[i]
                        if gcd(sa,sb)>1:
                            print("YES")
                            print(len(x),len(z))
                            print(*[i+1 for i in x])
                            print(*[i+1 for i in z])
                            f=1
                            break
                    if f: break
                if f: break
            if f: break
        if not f: print("NO")
    else:
        print("YES")
        e=[]
        o=[]
        i=0
        while i<n:
            if a[i]%2==0: e.append(i+1)
            else: o.append(i+1)
            i+=1
        if len(e)>=2:
            print("1 1")
            print(e[0])
            print(e[1])
        elif len(e)==0:
            print("2 2")
            print(o[0],o[1])
            print(o[2],o[3])
        else:
            print("2 1")
            print(o[0],o[1])
            print(e[0])

