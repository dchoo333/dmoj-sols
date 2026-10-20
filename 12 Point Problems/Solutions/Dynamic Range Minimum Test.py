from math import sqrt

n, q = map(int, input().split())
arr = [int(input()) for _ in range(n)]
w = int(sqrt(n))
m = [float('inf')] * ((n // w) + 1)

for i in range(n):
    m[i // w] = min(m[i // w], arr[i])

outs = []
for _ in range(q):
    q = input().split()
    i, j = map(int, q[1:])

    if q[0] == "M":
        arr[i] = j
        m[i // w] = min(arr[k] for k in range((i // w) * w, min((i // w + 1) * w, n)))
    else:
        res = float('inf')
        f, l = i // w + 1, j // w - 1

        if f > l:
            res = min(arr[i:j + 1])
        else:
            res = min(m[f:l + 1])
            if f * w > i:
                res = min(res, min(arr[i:f * w]))
            if (l + 1) * w <= j:
                res = min(res, min(arr[(l + 1) * w:j + 1]))

        outs.append(res)

for out in outs:
    print(out)