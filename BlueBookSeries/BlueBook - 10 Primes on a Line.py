def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def print_primes(M):
    primes = []
    num = 2
    while len(primes) < M:
        if is_prime(num):
            primes.append(num)
        num += 1

    for i in range(0, M, 10):
        print(*primes[i:i+10])
  M = int(input())
  print_primes(M)
