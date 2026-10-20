n = int(input())
a = list(map(int, input().split()))

u = d = 1
for i in range(1, n):
    if a[i] > a[i - 1]: u = d + 1
    elif a[i] < a[i - 1]: d = u + 1

print(max(u, d))