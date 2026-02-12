n = int(input())
c = [0]*1000

for _ in range(n):
    c[-int(input())] += 1

m1 = c.index(max(c))
c[m1] = 0
m2 = max(c)
se = [i for i,v in enumerate(c) if v==m2]

print(max(abs(m1 - min(se)), abs(m1 - max(se))))
