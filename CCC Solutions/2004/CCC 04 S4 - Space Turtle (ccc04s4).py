from math import sqrt
tx,ty,tz=map(float,input().split())
sx,sy,sz=map(float,input().split())
sx-=tx; sy-=ty; sz-=tz
sd=sx*sx+sy*sy+sz*sz

while True:
    l=input().split()
    d=float(l[0]); dir=l[1]
    tmp=sx-d
    if sx*tmp<0:
        sd=min(sd,sy*sy+sz*sz)
    else:
        sd=min(sd,tmp*tmp+sy*sy+sz*sz)
    sx=tmp
    if dir=='L': sx,sy=sy,-tmp
    elif dir=='R': sx,sy=-sy,tmp
    elif dir=='U': sx,sz=sz,-tmp
    elif dir=='D': sx,sz=-sz,tmp
    elif dir=='E': break

print(f"{sqrt(sd):.2f}")
