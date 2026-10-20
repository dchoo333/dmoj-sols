import sys

d = sys.stdin.read().split()
n, r, l = int(d[0]), int(d[1]), int(d[2])
L = [(int(d[3 + 2 * i]), int(d[4 + 2 * i])) for i in range(l)]

V = 2 * l
g = [[] for _ in range(V)]
rg = [[] for _ in range(V)]
def imp(a, b):
    g[a].append(b); rg[b].append(a)

for i in range(l):
    ri, ci = L[i]
    for j in range(i + 1, l):
        rj, cj = L[j]
        if ri == rj and abs(ci - cj) <= 2 * r:
            imp(2 * i, 2 * j + 1); imp(2 * j, 2 * i + 1)
        if ci == cj and abs(ri - rj) <= 2 * r:
            imp(2 * i + 1, 2 * j); imp(2 * j + 1, 2 * i)

seen = [False] * V
order = []
for s in range(V):
    if seen[s]: continue
    seen[s] = True
    st = [(s, 0)]
    while st:
        u, k = st[-1]
        if k < len(g[u]):
            st[-1] = (u, k + 1)
            w = g[u][k]
            if not seen[w]:
                seen[w] = True
                st.append((w, 0))
        else:
            st.pop(); order.append(u)

comp = [-1] * V
c = 0
for s in reversed(order):
    if comp[s] >= 0: continue
    comp[s] = c
    st = [s]
    while st:
        u = st.pop()
        for w in rg[u]:
            if comp[w] < 0:
                comp[w] = c
                st.append(w)
    c += 1

print("NO" if any(comp[2 * i] == comp[2 * i + 1] for i in range(l)) else "YES")