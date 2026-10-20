def ok(u, k, o, a, col):
    if u == len(o): return True
    x = o[u]
    for c in range(k):
        if all(col.get(y) != c for y in a[x]):
            col[x] = c
            if ok(u + 1, k, o, a, col): return True
            del col[x]
    return False

for _ in range(5):
    n = int(input())
    a = {}
    for _ in range(n):
        x, y = map(int, input().split())
        a.setdefault(x, set()); a.setdefault(y, set())
        if x != y: a[x].add(y); a[y].add(x)

    o = sorted(a, key=lambda v: -len(a[v]))
    r = 0
    for k in range(1, 5):
        if ok(0, k, o, a, {}): r = k; break
    print(r)