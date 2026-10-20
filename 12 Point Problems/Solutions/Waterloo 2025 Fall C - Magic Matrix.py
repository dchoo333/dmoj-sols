import sys
D = sys.stdin.buffer.read().split()
k = int(D[0])
r = [int(x) for x in D[1:1 + k]]
c = [int(x) for x in D[1 + k:1 + 2 * k]]
R, C = sum(r), sum(c)
gr = [g for g in range(k) for _ in range(r[g])]
gc = [g for g in range(k) for _ in range(c[g])]

V = R + C + 1
d = R + C
eu = []; ev = []
adj = [[] for _ in range(V)]
eid = [[-1] * C for _ in range(R)]

for i in range(R):
    a = gr[i]; row = eid[i]
    for j in range(C):
        if gc[j] != a:
            e = len(eu); eu.append(i); ev.append(R + j)
            adj[i].append(e); adj[R + j].append(e); row[j] = e

for v in range(R + C):
    if len(adj[v]) & 1:
        e = len(eu); eu.append(v); ev.append(d)
        adj[v].append(e); adj[d].append(e)

E = len(eu)
us = [False] * E
pt = [0] * V
cl = [0] * E

def run(s):
    st = [(s, -1)]; ph = []
    while st:
        v, e = st[-1]
        a = adj[v]; p = pt[v]
        while p < len(a) and us[a[p]]: p += 1
        pt[v] = p
        if p < len(a):
            f = a[p]; us[f] = True
            st.append((ev[f] if eu[f] == v else eu[f], f))
        else:
            st.pop()
            if e >= 0: ph.append(e)
    for t, e in enumerate(ph): cl[e] = t & 1

run(d)
for v in range(R + C):
    if pt[v] < len(adj[v]): run(v)

o = ["YES"]
for i in range(R):
    a = gr[i] + 1; row = eid[i]; s = []
    for j in range(C):
        e = row[j]
        s.append(a if e < 0 or cl[e] == 0 else gc[j] + 1)
    o.append(" ".join(map(str, s)))
print("\n".join(o))