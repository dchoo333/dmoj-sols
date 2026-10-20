t=0
while 1:
    r,c=map(int,input().split())
    if r==0 and c==0:break
    k=int(input())
    n=r*c
    g=[0]*n
    for _ in range(k):
        x,y=map(int,input().split())
        g[x*c+y]=1
    N=1<<n
    M=(1<<N)-1
    b=[]
    for i in range(n):
        h=1<<i
        b.append((((1<<h)-1)<<h)*(M//((1<<(2*h))-1)))
    o=M
    for i in range(n):
        x,y=divmod(i,c)
        d=[0,0,0,0]
        for p in(-1,0,1):
            for q in(-1,0,1):
                if p or q:
                    v=b[(x+p)%r*c+(y+q)%c]
                    for j in range(4):
                        u=d[j]&v
                        d[j]^=v
                        v=u
        z=d[1]&~d[2]&~d[3]&(d[0]|b[i])
        o&=z if g[i] else ~z&M
    m=bin(o).count('1')
    t+=1
    print(f"Case {t}: Garden of Eden." if m==0 else f"Case {t}: {m} possible ancestors.")