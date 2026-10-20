from math import comb
for t in range(1, int(input()) + 1):
    a, b = map(int, input().split('-'))
    x = (a - b) * comb(a + b, a) // (a + b)
    y = comb(2 * b, b) // (b + 1)
    print(f"Case #{t}: {x % (10**9 + 7)} {y % (10**9 + 7)}")