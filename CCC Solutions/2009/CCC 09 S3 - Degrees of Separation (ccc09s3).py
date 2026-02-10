from collections import deque

conn = [set() for _ in range(50)]

edges = [(1,6),(2,6),(3,4),(3,5),(3,6),(3,15),(4,5),(4,6),(5,6),(5,3),(6,7),(6,3),(6,4),(6,5),(7,8),(8,9),(9,10),(9,12),(10,11),(11,12),(13,12),(13,14),(13,15),(15,3),(16,17),(16,18),(17,18)]

for x,y in edges:
    conn[x].add(y)
    conn[y].add(x)

while True:
    cmd = input()
    if cmd == 'q':
        break
    elif cmd == 'i':
        x = int(input())
        y = int(input())
        conn[x].add(y)
        conn[y].add(x)
    elif cmd == 'd':
        x = int(input())
        y = int(input())
        conn[x].discard(y)
        conn[y].discard(x)
    elif cmd == 'n':
        x = int(input())
        print(len(conn[x]))
    elif cmd == 'f':
        x = int(input())
        s = set()
        for f in conn[x]:
            for ff in conn[f]:
                if ff != x and ff not in conn[x]:
                    s.add(ff)
        print(len(s))
    elif cmd == 's':
        x = int(input())
        y = int(input())
        q = deque([x])
        vs = [False]*50
        dist = [0]*50
        vs[x] = True
        found = False
        while q and not found:
            u = q.popleft()
            if u == y:
                found = True
                break
            for v in conn[u]:
                if not vs[v]:
                    vs[v] = True
                    dist[v] = dist[u]+1
                    q.append(v)
        print(dist[y] if vs[y] else "Not connected")
