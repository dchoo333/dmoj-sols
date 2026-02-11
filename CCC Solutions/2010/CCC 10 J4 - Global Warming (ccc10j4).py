while 1:
    l=input()
    if l=='0': break

    p=l.split()
    n=int(p[0])
    a=list(map(int,p[1:]))

    d=[a[i+1]-a[i] for i in range(n-1)]

    r=0
    for k in range(1,n):
        ok=1
        for i in range(n-1):
            if d[i]!=d[i%k]:
                ok=0
                break
        if ok:
            r=k
            break

    print(r)
