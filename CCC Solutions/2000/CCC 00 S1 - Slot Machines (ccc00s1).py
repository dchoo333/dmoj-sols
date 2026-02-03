q,f,s,t=map(int,[input() for _ in range(4)])
p=0
while q:
    m=p%3
    q-=1
    if m==0:
        f+=1
        q+=30*(f%35==0)
    elif m==1:
        s+=1
        q+=60*(s%100==0)
    else:
        t+=1
        q+=9*(t%10==0)
    p+=1
print(f'Martha plays {p} times before going broke.')
