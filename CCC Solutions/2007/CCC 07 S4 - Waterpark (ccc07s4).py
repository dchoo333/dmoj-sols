N = int(input())

adj = [[] for _ in range(N + 1)]
dp = [0] * (N + 1)

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    adj[a].append(b)

stk = [(1, 0)]

while stk:
    u, i = stk.pop()

    if i < len(adj[u]):
        v = adj[u][i]
        stk.append((u, i + 1))

        if v == N:
            dp[u] += 1
        elif dp[v] != 0:
            dp[u] += dp[v]
        else:
            stk.append((v, 0))
    else:
        if stk:
            pu, _ = stk[-1]
            dp[pu] += dp[u]

print(dp[1])
