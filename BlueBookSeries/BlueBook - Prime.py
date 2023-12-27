def is_prime(n):
    return n > 1 and all(n % i != 0 for i in range(2, int(n**0.5) + 1))

T = int(input())
for _ in range(T):
    N = int(input())
    print(1 if is_prime(N) else 0)
