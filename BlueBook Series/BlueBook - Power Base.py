def poww(x, p): return round(x ** p, 2)
for _ in range(int(input())):
    x, p = map(float, input().split())
    print(f"{poww(x, p):.2f}")