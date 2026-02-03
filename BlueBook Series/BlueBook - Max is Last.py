n = int(input())
a = [float(input()) for _ in range(n)]
m = max(a)
a.remove(m)
a.append(m)
for x in a:
    print(f"{x:.2f}")
