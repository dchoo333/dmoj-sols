h = int(input())
hs = sorted(int(input()) for _ in range(h))
k = int(input())

vis = [False] * 1001
ans = 10**6
l = 0
r = 10**6

while l <= r:
    mid = (l + r) // 2
    for i in range(1001):
        vis[i] = False

    hl = k

    for x in range(h):
        if vis[x]:
            continue
        if hl <= 0:
            break
        hl -= 1
        for y in range(h):
            if min(hs[y] - hs[x], 1000000 - hs[y] + hs[x]) <= 2 * mid:
                vis[y] = True

    if all(vis[:h]):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)
