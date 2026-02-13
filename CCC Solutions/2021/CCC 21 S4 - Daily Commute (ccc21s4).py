from collections import deque
import heapq

n, w, d = map(int, input().split())

walk, swap, route = [[] for _ in range(n + 1)], [], {}
for _ in range(w):
    a, b = map(int, input().split())
    walk[b].append(a)

tmp = list(map(int, input().split()))
for i, s in enumerate(tmp):
    route[i + 1] = s

for _ in range(d):
    x, y = map(int, input().split())
    swap.append((x, y))

st = (n, 0)
visited = {}
ft = deque()
ft.append(st)
while ft:
    s, l = ft.popleft()
    if visited.get(s) is None:
        visited[s] = l
        for nb in walk[s]:
            ft.append((nb, l + 1))

heap = []
for i in range(1, n + 1):
    st = route[i]
    if visited.get(st) is not None:
        t = (i - 1) + visited[st]
        heap.append((t, st, -1))
heapq.heapify(heap)

deld = {}
for day in range(d):
    p1, p2 = swap[day]
    s1, s2 = route[p1], route[p2]
    deld[s1], deld[s2] = day - 1, day - 1
    route[p1], route[p2] = route[p2], route[p1]

    if visited.get(s1) is not None:
        heapq.heappush(heap, ((p2 - 1) + visited[s1], s1, day))
    if visited.get(s2) is not None:
        heapq.heappush(heap, ((p1 - 1) + visited[s2], s2, day))

    while heap:
        item = heapq.heappop(heap)
        if deld.get(item[1]) is None or deld[item[1]] < item[2]:
            heapq.heappush(heap, item)
            print(item[0])
            break
