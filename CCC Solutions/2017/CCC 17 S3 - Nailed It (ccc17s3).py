n = int(input())
a = list(map(int, input().split()))
f = [0]*2001
p = [0]*4001

for x in a:
    f[x] += 1

for i in range(1, 2001):
    for j in range(i, 2001):
        if i == j:
            p[i+j] += f[i] // 2
        else:
            p[i+j] += min(f[i], f[j])

m = 0
c = 0
for x in range(1, 4001):
    if p[x] > m:
        m = p[x]
        c = 1
    elif p[x] == m:
        c += 1

print(m, c)
