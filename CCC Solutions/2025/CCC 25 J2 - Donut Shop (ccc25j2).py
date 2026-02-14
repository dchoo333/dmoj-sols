d, n = [int(input()) for _ in range(2)]

for _ in range(n):
    op = input()
    x = int(input())
    if op == '+':
        d += x
    else:
        d -= x

print(d)
