from collections import defaultdict
i, j, both = int(input()), int(input()), 0
squares = defaultdict(int)
h = int(i ** (1/6)) + 1 if round(i ** (1/6)) ** 6 < i else round(i**(1/6))
k = round(j**(1/6)) if round(j ** (1/6)) ** 6 > j else round(j ** (1/6)) + 1
print(k-h)
