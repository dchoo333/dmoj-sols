l,w,X=map(int,input().split())
r=set()
s=[(0,1,1,0,w)]

for _ in range(l):
    n=[]
    for x,y,dx,dy,w in s:
        t=w//3
        n+=[(x,y,dx,dy,t)]
        x1,y1=x+dx*t,y+dy*t
        px,py=-dy,dx
        n+=[(x1,y1,px,py,t)]
        x2,y2=x1+px*t,y1+py*t
        n+=[(x2,y2,dx,dy,t)]
        x3,y3=x2+dx*t,y2+dy*t
        n+=[(x3,y3,-px,-py,t)]
        x4,y4=x3-px*t,y3-py*t
        n+=[(x4,y4,dx,dy,t)]
    s=n

for x,y,dx,dy,w in s:
    if dx==0 and x==X:
        a,b=y,y+dy*w
        if a>b:a,b=b,a
        r.update(range(a,b+1))
    elif dx!=0 and (x<=X<=x+dx*w or x>=X>=x+dx*w):
        r.add(y)

print(*sorted(r))
