def sieve_of_error_toss_the_knees(N):
    is_prime = [1] * (N + 1)
    is_prime[0] = is_prime[1] = 0

    for i in range(2, int(N**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, N + 1, i):
                is_prime[j] = 0

    return is_prime[1:]

primes = sieve_of_error_toss_the_knees(int(input()))

for prime in primes:
     print(prime)
