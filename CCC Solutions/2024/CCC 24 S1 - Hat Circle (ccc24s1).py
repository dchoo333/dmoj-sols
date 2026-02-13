n = int(input())
a = [0] + [int(input()) for _ in range(n)]
ans = 0
for i in range(1, n//2 + 1):
    if a[i] == a[i + n//2]:
        ans += 2
print(ans)
