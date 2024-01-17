from collections import *
import sys

matrix = [[] for i in range(27)]
line = input()
edges = []
A = ord('A')
while line != '**':
    a, b = map(lambda c: ord(c) - A, list(line))
    edges.append((a, b))
    matrix[a].append(b)
    matrix[b].append(a)
    line = input()
cnt = 0
for a, b in edges:
    vis = [False for _ in range(27)]
    nextt = deque()
    vis[0] = True
    nextt.append(0)
    while nextt:
        curr = nextt.popleft()
        for adj in matrix[curr]:
            if (curr == a and adj == b) or (curr == b and adj == a) or vis[adj]:
                continue
            vis[adj] = True
            nextt.append(adj)
    if not vis[1]:
        cnt += 1
        print(chr(a + A) + chr(b + A))
print(f'There are {cnt} disconnecting roads.')