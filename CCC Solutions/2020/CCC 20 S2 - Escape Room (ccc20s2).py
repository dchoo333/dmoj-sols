from collections import deque

r = int(input())
c = int(input())

pos = [False] * 1000001
for i in range(1, r + 1):
    row = list(map(int, input().split()))
    for j in range(1, c + 1):
        v = row[j - 1]
        if not pos[v]:
            pos[v] = []
        pos[v].append([i, j])

q = deque([[r, c]])
vis = [[False] * (c + 1) for _ in range(r + 1)]
vis[r][c] = True
visnum = [False] * 1000001

while q:
    tr, tc = q.popleft()
    if tr == 1 and tc == 1:
        print("yes")
        break
    t = tr * tc
    if t <= 1000000 and not visnum[t]:
        visnum[t] = True
        if pos[t]:
            for nr, nc in pos[t]:
                if not vis[nr][nc]:
                    vis[nr][nc] = True
                    q.append([nr, nc])
else:
    print("no")
