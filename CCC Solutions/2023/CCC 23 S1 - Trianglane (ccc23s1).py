n = int(input())
c1 = list(map(int, input().split()))
c2 = list(map(int, input().split()))

cnt = sum(c1) + sum(c2)
ans = 3 * cnt

for i in range(n):
    if c1[i] == c2[i] == 1 and i % 2 == 0:
        ans -= 2
    if i < n - 1:
        if c1[i] == c1[i + 1] == 1:
            ans -= 2
        if c2[i] == c2[i + 1] == 1:
            ans -= 2

print(ans)