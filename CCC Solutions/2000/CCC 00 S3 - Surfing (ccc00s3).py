N = int(input())
links = []
docMap = {}

for _ in range(N):
    u = input().strip()
    arr = []
    while True:
        d = input().strip()
        if d == "</HTML>": break
        if "HREF" in d:
            for p in d.split('<A HREF="')[1:]:
                arr.append(p.split('"')[0])
    docMap[u] = docMap.get(u, []) + arr
    for v in arr:
        if u != v:
            links.append(f"Link from {u} to {v}")

while True:
    s = input().strip()
    if s == "The End": break
    t = input().strip()
    if t == "The End": break

    stack = [s]
    vis = set()
    can = False
    while stack and not can:
        src = stack.pop()
        if src == t:
            can = True
            break
        if src not in vis:
            vis.add(src)
            for nxt in docMap.get(src, []):
                if nxt not in vis:
                    stack.append(nxt)
    if can:
        links.append(f"Can surf from {s} to {t}.")
    else:
        links.append(f"Can't surf from {s} to {t}.")

print('\n'.join(links))
