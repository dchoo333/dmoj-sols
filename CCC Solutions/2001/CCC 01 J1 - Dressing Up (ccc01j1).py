n = int(input())

a = []
for i in range(1, n + 1, 2):
    a.append(i if i != n else i * 2)

for i in range(n, 0, -1):
    if (i - 1) % 2 == 1:
        a.append(i - 1 if i - 1 != n else (i - 1) * 2)

for x in a:
    if x == n * 2:
        print('*' * (n * 2))
    else:
        print('*' * x + ' ' * ((n - x) * 2) + '*' * x)
