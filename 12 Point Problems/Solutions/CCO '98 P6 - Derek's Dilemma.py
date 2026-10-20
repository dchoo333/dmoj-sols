from math import gcd
o=[]
while 1:
    n=int(input())
    if n==0:break
    s=n*(n+1)//2
    w=[gcd(a,s)==1 for a in range(s+1)]
    for t in range(n,0,-1):
        v=[False]*(s+1)
        for a in range(s-t+1):
            x,y=w[a],w[a+t]
            v[a]=(x or y) if t%2 else (x and y)
        w=v
    o.append(f"When n={n}, {'A' if w[0] else 'B'} will win.")
print("\n".join(o))