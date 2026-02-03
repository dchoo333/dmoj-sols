from collections import deque

d = int(input())
c = int(input())
clubs = [int(input()) for _ in range(c)]

q = deque([(0, 0)])
vis = [False] * (d + 1)
vis[0] = True
res = -1

while q:
    pos, st = q.popleft()
    if pos == d:
        res = st
        break
    for club in clubs:
        np = pos + club
        if np <= d and not vis[np]:
            vis[np] = True
            q.append((np, st + 1))

if res == -1:
    print("Roberta acknowledges defeat.")
else:
    print(f"Roberta wins in {res} strokes.")
