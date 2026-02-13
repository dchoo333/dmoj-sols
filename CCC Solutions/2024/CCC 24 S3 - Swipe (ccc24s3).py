n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

comp = []
l = 0
r = 0
while r < n:
    while r < n and b[l] == b[r]:
        r += 1
    comp.append((b[l], l, r-1))
    l = r

L = []
R = []
i = 0
j = 0
while i < n and j < len(comp):
    v, l, r = comp[j]
    if a[i] == v:
        if i > l:
            L.append((l, i))
        if i < r:
            R.append((i, r))
        j += 1
    i += 1

if j == len(comp):
    print("YES")
    print(len(L)+len(R))
    for l, r in L:
        print("L", l, r)
    R.reverse()
    for l, r in R:
        print("R", l, r)
else:
    print("NO")
