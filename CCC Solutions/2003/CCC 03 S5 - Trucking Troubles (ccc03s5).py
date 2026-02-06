import sys, heapq

n, e, d = map(int, input().split())
g = [[] for _ in range(n + 1)]
for _ in range(e):
    a, b, w = map(int, input().split())
    g[a].append((b, w))
    g[b].append((a, w))

best = [0] * (n + 1)
best[1] = 10**9
hq = [(-best[1], 1)]

while hq:
    bw, u = heapq.heappop(hq)
    bw = -bw
    if bw < best[u]: continue
    for v, w in g[u]:
        nw = min(bw, w)
        if nw > best[v]:
            best[v] = nw
            heapq.heappush(hq, (-nw, v))

ans = min(best[int(input())] for _ in range(d))
print(ans)
