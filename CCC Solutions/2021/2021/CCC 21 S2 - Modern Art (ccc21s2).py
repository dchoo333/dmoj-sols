m, n, k = [int(input()) for _ in range(3)]

r = [1]*m
c = [1]*n
g = 0

for _ in range(k):
    d, x = input().split()
    x = int(x)-1
    if d=="R": r[x]+=1
    if d=="C": c[x]+=1

for i in range(m):
    for j in range(n):
        if (r[i]+c[j])%2: g+=1

print(g)

