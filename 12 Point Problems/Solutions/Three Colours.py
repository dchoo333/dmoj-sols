s = input().strip()
n = len(s)
ch = [[] for _ in range(n)]
st = []
for i in range(n):
    if st:
        p = st[-1]
        ch[p].append(i)
        if len(ch[p]) == int(s[p]): st.pop()
    if s[i] != '0': st.append(i)

def func(f):
    R = [0] * n; X = [0] * n
    for v in range(n - 1, -1, -1):
        c = ch[v]
        if not c: R[v] = 1; X[v] = 0
        elif len(c) == 1:
            u = c[0]
            R[v] = 1 + X[u]; X[v] = f(R[u], X[u])
        else:
            l, r = c
            R[v] = 1 + X[l] + X[r]
            X[v] = f(R[l] + X[r], X[l] + R[r])
    return f(R[0], X[0])

print(func(max), func(min))