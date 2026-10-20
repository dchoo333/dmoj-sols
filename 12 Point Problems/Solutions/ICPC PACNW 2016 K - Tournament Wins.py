from math import lgamma, exp

k, r = map(int, input().split())
t = (1 << k) - 1
l = (1 << k) - r

s = 0.0
for j in range(1, k + 1):
    m = (1 << j) - 1
    if m > l: break
    s += exp(lgamma(l + 1) - lgamma(l - m + 1) - lgamma(t + 1) + lgamma(t - m + 1))

print(f"{s:.5f}")