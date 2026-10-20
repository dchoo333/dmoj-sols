def phi(m):
    n=m
    if m<=2:
        return 1
    i = 2
    while i*i<=m:
        if m%i==0:
            n//=i
            n*=i-1
            m//=i
            while m%i==0:
                m//=i
        i+=1
    if m>1:
        n//=m
        n*=m-1
    return n

def f(a, b, m):
    if m == 1:
        return 0
    if a == 2 and b == 4:
        e = 16
    elif a <= 5 and b == 3:
        e = a**a
    elif b == 2:
        e = a
    elif b == 1:
        return a
    else:
        pi = phi(m)
        e = f(a, b - 1, pi)
        e += pi
    return pow(a, e, m)

for _ in range(int(input())):
    a,b,m=map(int, input().split())
    if m == 1:
        print(0)
        continue
    if a <= 1:
        print(a)
        continue
    print(f(a, b, m) % m)