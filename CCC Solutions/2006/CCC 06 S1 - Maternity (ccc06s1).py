d, m = input(), input()
p = []
k = 0

for i in range(10):
    p += [min(d[i], m[k]), min(d[i], m[k+1])]
    if i % 2: k += 2

for _ in range(int(input())):
    b = input()
    ok = True
    for c in b:
        if c not in p:
            ok = False
            break
    print("Possible baby." if ok else "Not their baby!")
