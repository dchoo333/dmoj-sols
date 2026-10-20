n = int(input())
s = input().strip()

def norm(t):
    m = min(t)
    return (t[0] - m, t[1] - m, t[2] - m)

st = {(0, 0, 0)}
for ch in s:
    nx = set()
    for t in st:
        if ch == '~':
            m = min(t)
            for c in range(3):
                if t[c] == m:
                    u = list(t); u[c] += 1
                    nx.add(norm(u))
        else:
            u = list(t); u[int(ch) - 1] += 1
            nx.add(norm(u))
    st = nx

r = set()
for t in st:
    m = min(t)
    for c in range(3):
        if t[c] == m: r.add(c + 1)
print("\n".join(map(str, sorted(r))))