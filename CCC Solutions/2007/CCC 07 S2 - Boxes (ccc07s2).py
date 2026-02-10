def ok(a, b):
    a = sorted(a)
    b = sorted(b)
    return a[0] <= b[0] and a[1] <= b[1] and a[2] <= b[2]

n = int(input())
dims = []
vol = []

for _ in range(n):
    a, b, c = map(int, input().split())
    dims.append([a, b, c])
    vol.append(a * b * c)

q = int(input())

for _ in range(q):
    x = list(map(int, input().split()))
    best = None

    for i in range(n):
        if ok(x, dims[i]):
            if best is None or vol[i] < best:
                best = vol[i]

    if best is None:
        print("Item does not fit.")
    else:
        print(best)
