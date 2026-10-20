import sys, heapq
D = sys.stdin.buffer.read().split()
n, m, T = int(D[0]), int(D[1]), int(D[2])
P = sorted(zip(map(int, D[3:3 + 2 * m:2]), map(int, D[4:4 + 2 * m:2])))

h = [0] * n
E = []
for t, f in P:
    s = max(t, heapq.heappop(h))
    heapq.heappush(h, s + f)
    E.append(2 * s + 1)
    E.append(2 * (s + f))
E.sort()

x = 0
c = 0
for e in E:
    p = e >> 1
    if e & 1:
        c += 1
        if c == n: a = p
    else:
        if c == n:
            if x + T <= a: break
            x = max(x, p)
        c -= 1

print(x)