n = int(input())
ls = sorted(lst(map(int, input().split())))
half = (n // 2) + (n % 2)
lss = [iter(reversed(ls[:half])), iter(ls[half:])]

print(' '.join([str(next(lss[i % 2])) for i in range(n)]))
