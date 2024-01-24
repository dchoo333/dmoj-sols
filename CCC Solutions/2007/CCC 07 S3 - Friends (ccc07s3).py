from collections import deque

adj = [[] for _ in range(10000)]
q = deque()

n, t1, t2 = 0, 0, 0

def bfs(a, b):
    used = [False] * 10000
    dist = [0] * 10000
    q.append(a)
    used[a] = True
    while q:
        v = q.popleft()
        for u in adj[v]:
            if not used[u]:
                used[u] = True
                q.append(u)
                dist[u] = dist[v] + 1

    print("Yes " + str(dist[b] - 1) if used[b] else "No")

n = int(input())
for _ in range(n):
    t1, t2 = map(int, input().split())
    adj[t1].append(t2)

while True:
    t1, t2 = map(int, input().split())
    if t1 == 0 and t2 == 0:
        break
    bfs(t1, t2)