def p(x):
    if x < 2:
        return 0
    i = 2
    while i * i <= x:
        if x % i == 0:
            return 0
        i += 1
    return 1

def g(m):
    a = []
    v = 2
    while len(a) < m:
        if p(v):
            a.append(v)
        v += 1
    i = 0
    while i < m:
        print(*a[i:i+10])
        i += 10

n = int(input())
g(n)
