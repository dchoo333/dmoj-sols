def wht(a):
    n = len(a)
    h = 1
    while h < n:
        for i in range(0, n, h * 2):
            for j in range(i, i + h):
                x, y = a[j], a[j + h]
                a[j] = x + y
                a[j + h] = x - y
        h *= 2

def iwht(a):
    wht(a)
    n = len(a)
    for i in range(n):
        a[i] /= n

N, X = map(int, input().split())
probs = [float(x) for x in input().split()]

SIZE = 128 
p = [0.0] * SIZE
for i in range(X + 1):
    p[i] = probs[i]

wht(p)

for i in range(SIZE):
    p[i] = p[i] ** N

iwht(p)

print(f"{1.0 - p[0]:.9f}")
