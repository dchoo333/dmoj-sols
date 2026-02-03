def a(x, b):
    p = 0
    r = 0
    while x:
        r += (x % 10) * (b ** p)
        x //= 10
        p += 1
    return r

def d(x, b):
    t = 0
    m = 1
    while x:
        t += (x % b) * m
        m *= 10
        x //= b
    return t

k = int(input())
j = 0
while j < k:
    b1 = int(input())
    n1 = int(input())
    b2 = int(input())
    n2 = int(input())
    o = input().strip()
    bf = int(input())

    u = a(n1, b1)
    v = a(n2, b2)

    if o == "+":
        w = u + v
    elif o == "-":
        w = u - v
    elif o == "*":
        w = u * v
    else:
        w = u // v

    print(d(w, bf))

    j += 1
    if j < k:
        input()
