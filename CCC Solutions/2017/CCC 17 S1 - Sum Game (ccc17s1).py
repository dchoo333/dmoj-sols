n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
s1 = s2 = h = 0
for i in range(n):
    s1 += a[i]
    s2 += b[i]
    if s1 == s2:
        h = i + 1
print(h)
