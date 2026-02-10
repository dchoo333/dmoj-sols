from collections import *
import sys

ans = []
for _ in range(int(input())):
    r = int(input())
    c = int(input())
    grid = []
    for _ in range(r):
        grid.append(input())
    dist = [[-1 for i in range(c)] for i in range(r)]
    nextt = deque()
    nextt.append((0, 0))
    dist[0][0] = 1
    while nextt:
        cx, cy = nextt.popleft()
        dx = dist[cx][cy]
        adjs = ()
        if grid[cx][cy] == '+':
            adjs = ((cx + 1, cy), (cx - 1, cy), (cx, cy + 1), (cx, cy - 1))
        elif grid[cx][cy] == '|':
            adjs = ((cx + 1, cy), (cx - 1, cy))
        elif grid[cx][cy] == '-':
            adjs = ((cx, cy + 1), (cx, cy - 1))
        for ax, ay in adjs:
            if ax < 0 or ax >= r or ay < 0 or ay >= c or dist[ax][ay] != -1:
                continue
            dist[ax][ay] = dx + 1
            nextt.append((ax, ay))
    if grid[r - 1][c - 1] == '*':
        ans.append('-1')
    else:
        ans.append(str(dist[r - 1][c - 1]))
for item in ans:
    print(item)