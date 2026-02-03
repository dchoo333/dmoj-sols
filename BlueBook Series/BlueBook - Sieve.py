def sieve(N):
    y = [1] * (N + 1)
    y[0] = y[1] = 0

    for i in range(2, int(N**0.5) + 1):
        if y[i]:
            for j in range(i*i, N + 1, i):
                y[j] = 0

    return y[1:]

primes = sieve(int(input()))

for prime in primes:
     print(prime)