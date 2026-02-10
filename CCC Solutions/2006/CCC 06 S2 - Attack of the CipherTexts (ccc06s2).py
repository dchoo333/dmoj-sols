p = input()
c = input()
d = input()

mp = {}
ks = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ ")
vs = ks[:]

for i in range(len(p)):
    mp[c[i]] = p[i]
    if c[i] in ks: ks.remove(c[i])
    if p[i] in vs: vs.remove(p[i])

if len(ks) == 1:
    mp[ks[0]] = vs[0]

out = ""
for x in d:
    out += mp[x] if x in mp else "."

print(out)
