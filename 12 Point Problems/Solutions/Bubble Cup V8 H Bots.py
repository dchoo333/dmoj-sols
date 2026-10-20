m = 1000000007

n = int(input())

N = 2*n + 2
k = n + 1

a = 1
b = 1

for i in range(k):
    a = a * (N - i) % m
    b = b * (i + 1) % m

r = 1
e = m - 2
x = b

while e > 0:
    if e % 2:
        r = r * x % m
    x = x * x % m
    e //= 2

print((a * r - 1) % m)