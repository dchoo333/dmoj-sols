n = int(input())
k = int(input())
dp = [[0]*(k+1) for _ in range(n+1)]

for i in range(n+1):
    for j in range(1, k+1):
        if i < j:
            dp[i][j] = 0
        elif i == j or j == 1:
            dp[i][j] = 1
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-j][j]

print(dp[n][k])
