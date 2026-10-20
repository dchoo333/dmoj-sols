n, l, u = map(int, input().split())
w = list(map(int, input().split()))
o = sorted(range(n), key=lambda x: w[x])

s = i = 0
a = None
for j in range(n):
    s += w[o[j]]
    while s > u:
        s -= w[o[i]]; i += 1
    if s >= l:
        a = o[i:j + 1]
        break

if a: print(len(a)); print(*sorted(a))
else: print(0)