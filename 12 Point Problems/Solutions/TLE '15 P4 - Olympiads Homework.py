n = int(input())
p = 10 ** 9 + 13
R = [1, 1, 0, -2, -4, -4, 0, 8]

if n == 0: print(1)
else: print((pow(2, n, p) + 2 * R[n % 8] * pow(16, n // 8, p)) * pow(4, -1, p) % p)