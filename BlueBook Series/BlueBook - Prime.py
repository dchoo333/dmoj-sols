def p(n):
    return n > 1 and all(n % i for i in range(2, int(n**0.5)+1))

for _ in range(int(input())):
    print(1 if p(int(input())) else 0)
