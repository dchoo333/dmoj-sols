n = int(input())
a = [int(input()) for _ in range(n)]

v = [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000]

for x in a:
    v[x - 1] = 0

c = 10 - n
s = sum(v)
m = int(input())

if s / c < m:
    print("deal")
else:
    print("no deal")
