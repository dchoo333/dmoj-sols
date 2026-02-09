while 1:
    m,n=map(int,input().split())
    if m+n==0: break
    g=[input().strip() for _ in range(m)]
    dp=[[-10**9]*n for _ in range(m)]
    dp[m-1][0]=-10**9 if g[m-1][0]=='*' else 0 if g[m-1][0]=='.' else int(g[m-1][0])
    for r in range(m-2,-1,-1): dp[r][0]=dp[r+1][0]+(-10**9 if g[r][0]=='*' else 0 if g[r][0]=='.' else int(g[r][0])) if dp[r+1][0]>-10**9 and g[r][0]!='*' else -10**9
    for c in range(1,n):
        d=[-10**9]*m; u=[-10**9]*m
        for r in range(m):
            v=-10**9 if g[r][c]=='*' else 0 if g[r][c]=='.' else int(g[r][c])
            d[r]=u[r]=dp[r][c-1]+v if v>-10**9 and dp[r][c-1]>-10**9 else -10**9
        for r in range(1,m): v=-10**9 if g[r][c]=='*' else 0 if g[r][c]=='.' else int(g[r][c]); d[r]=max(d[r],d[r-1]+v) if d[r-1]>-10**9 and v>-10**9 else d[r]
        for r in range(m-2,-1,-1): v=-10**9 if g[r][c]=='*' else 0 if g[r][c]=='.' else int(g[r][c]); u[r]=max(u[r],u[r+1]+v) if u[r+1]>-10**9 and v>-10**9 else u[r]
        for r in range(m): dp[r][c]=max(d[r],u[r])
    print(dp[m-1][n-1])
