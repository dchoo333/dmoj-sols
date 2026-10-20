s = [input().strip() for _ in range(4)]
p = input().strip()
L = len(p)

es = [e for e in s if e]
mn = min(len(e) for e in es)
K = max(len(e) for e in es) + 1
R = L // mn + 1
W = 2 * R + 3
mv = [W, -W, 1, -1]

st = [0] * K
st[0] = 1 << (R * W + R)

for i in range(L):
    cur = st[i % K]
    if not cur: continue
    st[i % K] = 0
    for d in range(4):
        e = s[d]
        if e and p.startswith(e, i):
            k = mv[d]
            j = (i + len(e)) % K
            st[j] |= cur << k if k > 0 else cur >> -k

print(bin(st[L % K]).count('1'))