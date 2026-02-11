sx,sy=map(lambda x:int(x)-1,input().split())
ex,ey=map(lambda x:int(x)-1,input().split())

d=[[64]*8 for _ in range(8)]
d[sx][sy]=0

q=[sx*8+sy]
i=0

while i<len(q):
    p=q[i]; i+=1
    x=p//8; y=p%8
    v=d[x][y]+1

    for a in (-2,-1,1,2):
        for b in (-2,-1,1,2):
            if abs(a)!=abs(b):
                nx=x+a; ny=y+b
                if 0<=nx<8 and 0<=ny<8 and v<d[nx][ny]:
                    d[nx][ny]=v
                    q.append(nx*8+ny)

print(d[ex][ey])
