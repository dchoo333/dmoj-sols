def f(n, r, y):
    return [(i, round(n * (1 + r / 100) ** i, 2)) for i in range(y + 1)]

n, m, y = map(float, input().split())
for i, a in f(n, m, int(y)):
    print(f"{i} {a:.2f}")
