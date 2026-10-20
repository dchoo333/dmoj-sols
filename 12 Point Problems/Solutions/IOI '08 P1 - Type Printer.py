n = int(input())
ws = [input().strip() for _ in range(n)]
lw = max(ws, key=len)

def k(w):
    r = []
    on = True
    for i, c in enumerate(w):
        on = on and i < len(lw) and c == lw[i]
        r.append('{' if on else c)
    return ''.join(r)

ws.sort(key=k)

o = []
p = ''
for w in ws:
    l = 0
    m = min(len(p), len(w))
    while l < m and p[l] == w[l]: l += 1
    o.append('-' * (len(p) - l) + w[l:] + 'P')
    p = w

s = ''.join(o)
print(len(s))
print('\n'.join(s))