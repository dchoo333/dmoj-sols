import heapq

K, N, M = map(int, input().split())
g = [[] for _ in range(N + 1)]

for _ in range(M):
    ai, bi, ti, hi = map(int, input().split())
    g[ai].append((bi, ti, hi))
    g[bi].append((ai, ti, hi))

A, B = map(int, input().split())

pq = []
heapq.heappush(pq, (0, A, 0))

mt = [[float('inf')] * (K + 1) for _ in range(N + 1)]
mt[A][0] = 0
run = True
while pq:
    ct, ci, ch = heapq.heappop(pq)

    if ci == B:
        print(ct)
        run = False
        break

    for n, tt, hw in g[ci]:
        nh = ch + hw
        nt = ct + tt
        if nh < K and nt < mt[n][nh]:
            mt[n][nh] = nt
            heapq.heappush(pq, (nt, n, nh))
if run:
    print(-1)
