n = int(input())
dp = {1: 1}

def func(w):
    if w in dp:
        return dp[w]
    ans = 0
    s = w
    while s > 1:
        x = w // s
        e = w // (x + 1)
        ans += (s - e) * func(x)
        s = e
    dp[w] = ans
    return ans

print(func(n))
