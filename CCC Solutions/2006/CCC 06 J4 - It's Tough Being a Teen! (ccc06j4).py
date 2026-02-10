g = [[0]*10 for _ in range(10)]
c = [0]*10

g[1][7] = g[1][4] = 1
g[2][1] = 1
g[3][4] = g[3][5] = 1

c[7] = 1
c[4] = 2
c[1] = 1
c[5] = 1

while True:
    a = int(input())
    b = int(input())
    if a == 0 or b == 0:
        break
    g[a][b] = 1
    c[b] += 1

o = [0]*10
i = 0

for _ in range(1, 8):
    for j in range(1, 8):
        if c[j] == 0:
            i += 1
            o[i] = j
            c[j] = -1
            for k in range(1, 8):
                if g[j][k]:
                    g[j][k] = 0
                    c[k] -= 1
            break

if i < 7:
    print("Cannot complete these tasks. Going to bed.")
else:
    print(*o[1:8])
