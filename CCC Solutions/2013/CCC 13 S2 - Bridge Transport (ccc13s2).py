ms, b, p1, p2, p3, i = int(input()), int(input()), 0, 0, 0, 0

for _ in range(b):
    c = int(input())
    if c + p1 + p2 + p3 > ms: break
    p3, p2, p1, i = p2, p1, c, i + 1

print(i)