from math import isqrt, pi

t = int(input())
for _ in range(t):
    h = int(input())
    if h <= 20000:
        h2 = h * h
        print(sum(isqrt(h2 - a * a) for a in range(1, h + 1)))
    else:
        print(round(pi * h * h / 4 - h - 0.25))