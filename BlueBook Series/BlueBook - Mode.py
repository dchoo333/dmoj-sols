def m(d):
    c = {}
    for x in d:
        if x in c:
            c[x] += 1
        else:
            c[x] = 1
    mx = max(c.values())
    return sorted(k for k, v in c.items() if v == mx)

a = []
while (x := int(input())) != -1:
    a.append(x)

for v in m(a):
    print(v)
