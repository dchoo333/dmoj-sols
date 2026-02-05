from collections import deque

g = [[] for _ in range(27)]
e = []
A = ord('A')

while True:
    line = input()
    if line == '**': break
    a, b = ord(line[0])-A, ord(line[1])-A
    e.append((a,b))
    g[a].append(b)
    g[b].append(a)

cnt = 0
for a,b in e:
    vis = [False]*27
    q = deque([0])
    vis[0] = True
    while q:
        x = q.popleft()
        for y in g[x]:
            if (x==a and y==b) or (x==b and y==a) or vis[y]:
                continue
            vis[y] = True
            q.append(y)
    if not vis[1]:
        print(chr(a+A)+chr(b+A))
        cnt += 1

print(f'There are {cnt} disconnecting roads.')
