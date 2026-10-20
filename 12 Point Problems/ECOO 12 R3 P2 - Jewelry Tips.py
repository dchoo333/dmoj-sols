import sys
D=[(0,-1,'LT'),(-1,0,'UP'),(0,1,'RT'),(1,0,'DN')]
T=['Norm','Good','Excl']
def f(g,p):
    o=[]
    for i in range(8):
        j=0
        while j<8:
            k=j
            while k<8 and g[i][k]==g[i][j]:k+=1
            if k-j>2:
                s={(i,x) for x in range(j,k)}
                if s&p:o.append((g[i][j],k-j,s))
            j=k
    for j in range(8):
        i=0
        while i<8:
            k=i
            while k<8 and g[k][j]==g[i][j]:k+=1
            if k-i>2:
                s={(x,j) for x in range(i,k)}
                if s&p:o.append((g[i][j],k-i,s))
            i=k
    return o
r=[]
for l in sys.stdin.read().split('\n'):
    t=''.join(l.split())
    if t:r.append(t)
for b in range(0,len(r),8):
    g=[list(x) for x in r[b:b+8]]
    w=[]
    for i in range(8):
        for j in range(8):
            for d in range(4):
                y,x,nm=D[d]
                a,c=i+y,j+x
                if not(0<=a<8 and 0<=c<8):continue
                if g[i][j]==g[a][c]:continue
                g[i][j],g[a][c]=g[a][c],g[i][j]
                o=f(g,{(i,j),(a,c)})
                if o:
                    t=2 if len(o)>1 else min(o[0][1]-3,2)
                    if any(z[0]==g[a][c] and (a,c) in z[2] for z in o):w.append((t,i,j,d,g[a][c],nm))
                g[i][j],g[a][c]=g[a][c],g[i][j]
    if w:
        t,i,j,d,co,nm=min(w)
        print('%s: %s.%s@%d,%d'%(T[t],co,nm,i,j))
    else:print('Game Over')