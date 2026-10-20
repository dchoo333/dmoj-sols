# language based memory when
# anyways all last 5 will be in python (hopefully should be possible)

from array import array
n = int(input())
A = array('i', [0])*(n - 1)
B = array('i', [0])*(n - 1)
dg = array('i', [0])*(n + 2)
for i in range(n - 1):
    a, b = input().split()
    a = int(a); b = int(b)
    A[i] = a; B[i] = b
    dg[a] += 1; dg[b] += 1

s = array('i', [0]) * (n + 2)
for v in range(1, n + 1): s[v + 1] = s[v] + dg[v]
pos = array('i', s)
adj = array('i', [0]) * (2 * (n - 1))
for i in range(n - 1):
    a = A[i]; b = B[i]
    adj[pos[a]] = b
    pos[a] += 1
    adj[pos[b]] = a
    pos[b] += 1
del A, B, pos, dg

par = array('i', [0]) * (n + 1)
order = array('i')
vis = bytearray(n + 1)
st = array('i', [1])
vis[1] = 1

while st:
    u = st.pop()
    order.append(u)
    for k in range(s[u], s[u + 1]):
        v = adj[k]
        if not vis[v]:
            vis[v] = 1
            par[v] = u
            st.append(v)

bd = array('i', [0]) * (n + 1)
bc = array('i', [1]) * (n + 1)
L, cnt = -1, 0
for j in range(len(order) - 1, -1, -1):
    u = order[j]
    p = par[u]
    if not p: continue
    d = bd[u] + 1; c = bc[u]
    t = bd[p] + d
    if t > L:
        L = t
        cnt = bc[p] * c
    elif t == L:
        cnt += bc[p] * c
    if d > bd[p]:
        bd[p] = d
        bc[p] = c
    elif d == bd[p]:
        bc[p] += c

print(cnt)