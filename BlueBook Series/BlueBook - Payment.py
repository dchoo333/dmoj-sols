r = {'A':range(0,9999),'B':range(10000,20000),'C':range(20000,30000),
     'D':range(30000,40000),'E':range(40000,50000),'F':range(50000,1000000)}

c = {k:0 for k in r}
a = []

while (x:=int(input())) != -1:
    a.append(x)

for n in a:
    for k,v in r.items():
        if n in v:
            c[k] += 1
            break
    else:
        c['F'] += 1

for k in ['A','B','C','D','E','F']:
    print(c[k])
