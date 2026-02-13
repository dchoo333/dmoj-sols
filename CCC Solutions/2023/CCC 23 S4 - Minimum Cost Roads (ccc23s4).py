import heapq

N, M = map(int, input().split())

roads = []
g = [[] for _ in range(N + 1)]

for _ in range(M):
    u, v, l, c = map(int, input().split())
    roads.append([c, l, u, v])
    g[u].append([l, v])
    g[v].append([l, u])

roads.sort(key=lambda x: x[0], reverse=True)

ans = 0

for c, l, u, v in roads:
    uv = [l, v]
    vu = [l, u]

    g[u].remove(uv)
    g[v].remove(vu)
    dist = [float('inf')] * (N + 1)
    dist[u] = 0
    pq = [(0, u)]

    while pq:
        d, node = heapq.heappop(pq)
        if d > dist[node]:
            continue
        for w, nxt in g[node]:
            nd = d + w
            if nd < dist[nxt]:
                dist[nxt] = nd
                heapq.heappush(pq, (nd, nxt))

    if dist[v] > l:
        g[u].append(uv)
        g[v].append(vu)
        ans += c

print(ans)

