w = int(input())
s = 'WELCOME TO CCC GOOD LUCK TODAY'
words = s.split()
lines = []
cur = []
l = 0

for x in words:
    if l + len(x) + len(cur) > w:
        lines.append(cur)
        cur = []
        l = 0
    cur.append(x)
    l += len(x)
lines.append(cur)

for ln in lines:
    ts = w - sum(len(x) for x in ln)
    g = len(ln) - 1
    if g == 0:
        print(".".join(ln).ljust(w, '.'))
    else:
        se = ts // g
        ex = ts % g
        out = ""
        for i, x in enumerate(ln):
            out += x
            if i < g:
                out += "." * (se + (1 if i < ex else 0))
        print(out)
