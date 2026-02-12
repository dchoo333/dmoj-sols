T = int(input())
n = int(input())
a = sorted(int(input()) for _ in range(n))
s = c = 0
for x in a:
    if s + x <= T:
        s += x
        c += 1
print(c)
