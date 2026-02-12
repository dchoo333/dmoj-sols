l = "abcdefghijklmnopqrstuvwxyz"
c = "bcdfghjklmnpqrstvwxyz"
v = "aeiou"
vi = [0, 4, 8, 14, 20, 0]

w = list(input().strip())

for i, x in enumerate(w):
    if x in v:
        continue
    for j in range(5):
        if abs(l.index(x) - vi[j]) <= abs(l.index(x) - vi[j+1]):
            nv = l[vi[j]]
            break
    if x == "z":
        nc = "z"
    else:
        idx = c.index(x)
        nc = c[idx + 1] if idx + 1 < len(c) else "z"
    w[i] = x + nv + nc

print("".join(w))
