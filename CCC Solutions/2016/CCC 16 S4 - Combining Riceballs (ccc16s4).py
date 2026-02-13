n = int(input())
a = list(map(int, input().split()))
mx = max(a)
p = [0]*(n+1)
for i in range(n):
    p[i+1] = p[i]+a[i]

dp = [[0]*n for _ in range(n)]
for i in range(n):
    dp[i][i] = 1

for d in range(1, n):
    for i in range(n-d):
        j = i+d
        l, r = i+1, j-1
        while l <= r:
            if dp[i][l-1] and dp[l][r] and dp[r+1][j] and p[l]-p[i]==p[j+1]-p[r+1]:
                dp[i][j] = 1
                break
            elif p[j+1]-p[r+1] > p[l]-p[i]:
                l += 1
            else:
                r -= 1
        if dp[i][l-1] and dp[r+1][j] and p[l]-p[i]==p[j+1]-p[r+1]:
            dp[i][j] = 1
        if dp[i][j]:
            mx = max(mx, p[j+1]-p[i])

print(mx)
