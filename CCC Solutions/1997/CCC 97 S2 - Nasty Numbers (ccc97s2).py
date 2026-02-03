for _ in range(int(input())):
    n = int(input())
    p = []
    m = int(n ** 0.5)
    for i in range(1, m + 1):
        q, r = divmod(n, i)
        if r == 0:
            p.append(q - i)
            p.append(i + q)
    yes = False
    for x in p:
        if p.count(x) != 1:
            yes = True
            break
    if yes:
        print(f"{n} is nasty")
    else:
        print(f"{n} is not nasty")
