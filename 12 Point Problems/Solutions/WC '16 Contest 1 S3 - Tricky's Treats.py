import sys, heapq
D = sys.stdin.buffer.read().split()
n, m, t = int(D[0]), int(D[1]), int(D[2])
H = sorted(zip(map(int, D[3:3 + 2 * n:2]), map(int, D[4:4 + 2 * n:2])))

h = []
s = b = 0
for p, c in H:
    if 2 * p > m: break
    k = (m - 2 * p) // t
    heapq.heappush(h, c); s += c
    while len(h) > k: s -= heapq.heappop(h)
    if s > b: b = s

print(b)