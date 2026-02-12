G = int(input())
P = int(input())

p = list(range(G + 1))
cnt = 0
lst = [int(input()) for _ in range(P)]

for i in range(P):
    g = lst[i]
    gate = g
    while p[gate] != gate:
        p[gate] = p[p[gate]]
        gate = p[gate]
    if gate == 0:
        break
    cnt += 1
    gp = gate - 1
    while p[gp] != gp:
        p[gp] = p[p[gp]]
        gp = p[gp]
    p[gate] = gp

print(cnt)
