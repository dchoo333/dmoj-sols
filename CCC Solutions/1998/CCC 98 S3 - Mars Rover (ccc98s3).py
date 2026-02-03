def goH():
    global f
    if h>0:
        if f%4==0: print(3); f-=1
        elif f%4==2: print(2); f+=1
        elif f%4==1: print(2); print(2); f+=2
    elif h<0:
        if f%4==0: print(2); f+=1
        elif f%4==2: print(3); f-=1
        elif f%4==3: print(2); print(2); f+=2
    print(1); print(abs(h))

def goV():
    global f
    if v>0:
        if f%4==1: print(2); f+=1
        elif f%4==3: print(3); f-=1
        elif f%4==0: print(2); print(2); f+=2
    elif v<0:
        if f%4==3: print(2); f+=1
        elif f%4==1: print(3); f-=1
        elif f%4==2: print(2); print(2); f+=2
    print(1); print(abs(v))

n=int(input())
for _ in range(n):
    h=v=f=0
    while True:
        m=int(input())
        if m==0: break
        if m==1:
            a=int(input())
            if f%4==0: v+=a
            elif f%4==2: v-=a
            elif f%4==3: h-=a
            elif f%4==1: h+=a
        elif m==2: f+=1
        else: f-=1
    t=abs(h)+abs(v)
    print(f"Distance is {t}")
    if t!=0:
        vg=-1
        if v>0: vg=2
        elif v<0: vg=0
        hg=-1
        if h>0: hg=3
        elif h<0: hg=1
        if h==0: goV()
        elif v==0: goH()
        elif f%2==0 and f%4==vg: goV(); goH()
        elif f%2==0 and f%4!=vg: goH(); goV()
        elif f%2==1 and f%4==hg: goH(); goV()
        elif f%2==1 and f%4!=hg: goV(); goH()
