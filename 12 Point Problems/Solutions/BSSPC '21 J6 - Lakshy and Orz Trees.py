n = int(input())
if n == 1:
    print(0)
else:
    v = [0, 0] + list(map(int, input().split()))
    adj = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)

    par = [0] * (n + 1)
    par[1] = -1
    order = [1]
    for u in order:
        for w in adj[u]:
            if w != par[u]:
                par[w] = u
                order.append(w)

    S = v[:]
    dp = [0] * (n + 1)
    for u in reversed(order):
        tot = 0
        sav = []
        for c in adj[u]:
            if c != par[u]:
                tot += S[c]
                sav.append(S[c] - dp[c])
        S[u] += tot
        sav.sort(reverse=True)
        dp[u] = tot - sum(sav[:3 if u == 1 else 2])

    print(dp[1])
