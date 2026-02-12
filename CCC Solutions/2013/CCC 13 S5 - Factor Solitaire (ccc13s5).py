n = int(input()); ans = 0
while n != 1: ans += next((n - (n // x)) // (n // x) for x in range(2, n + 3) if n % x == 0); n -= n // next(x for x in range(2, n + 3) if n % x == 0)
print(ans)