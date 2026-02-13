l = [0] * 500001
dp = [0.0] * 500001

n = int(input())
b = [int(i) for i in input().split()]

for i in range(n):
    l[b[i]] = i
    
c = b[0]
j = b[n - 1]
tk = 1.0 / n
for i in range(1, n):
    want = b[i]
    if want != c:
        dp[want] += tk
    if l[want] == i:
        tk += dp[want] / (n - i)
print(f"{1-dp[j]:.9f}")