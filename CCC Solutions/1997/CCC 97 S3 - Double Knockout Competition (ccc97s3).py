def f(u):
    r = l = e = 0
    while True:
        print(f"Round {r}: {u} undefeated, {l} one-loss, {e} eliminated")
        if r and ((u == 1 and l == 0 and e == 0) or (u == 0 and l == 1)):
            return r
        if u == 1:
            if l == 1:
                u = 0
                l = 2
            else:
                e += l // 2
                l -= l // 2
        else:
            e += l // 2
            l -= l // 2
            l += u // 2
            u -= u // 2
        r += 1

t = int(input())
a = [int(input()) for _ in range(t)]

for i,x in enumerate(a):
    k = f(x)
    print(f"There are {k} rounds.")
    if i < t-1:
        print()
