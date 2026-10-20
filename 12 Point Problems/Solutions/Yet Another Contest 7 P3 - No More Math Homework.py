import sys
D = sys.stdin.buffer.read().split()
n = int(D[0])
P = [0] + [int(x) for x in D[1:1 + n]]

def go(P):
    st = bytearray(n + 1)
    ix = [0] * (n + 1)
    cid = [0] * (n + 1)
    lab = [0] * (n + 1)
    dep = [0] * (n + 1)
    Ls = []
    for s in range(1, n + 1):
        if st[s]: continue
        path = []; u = s
        while not st[u]:
            st[u] = 1; ix[u] = len(path); path.append(u); u = P[u]
        k = len(path)
        if st[u] == 1:
            k = ix[u]; L = len(path) - k
            c = len(Ls); Ls.append(L)
            for j in range(k, len(path)):
                v = path[j]; cid[v] = c; lab[v] = j - k; st[v] = 2
        for j in range(k - 1, -1, -1):
            v = path[j]; w = P[v]
            cid[v] = cid[w]; dep[v] = dep[w] + 1
            lab[v] = (lab[w] - 1) % Ls[cid[w]]; st[v] = 2
    return cid, lab, dep, Ls

cid, lab, dep, Ls = go(P)
b = max(range(1, n + 1), key=dep.__getitem__)
if dep[b] == 0:
    A, B = 1, P[1]
else:
    A = b
    for _ in range(dep[b] - 1): A = P[A]
    B = b
P[A] = B

cid, lab, dep, Ls = go(P)
bs = [0] * (len(Ls) + 1)
for i, L in enumerate(Ls): bs[i + 1] = bs[i] + L

sys.stdout.write(f"{A} {B}\n" + " ".join(str(bs[cid[v]] + lab[v] + 1) for v in range(1, n + 1)) + "\n")