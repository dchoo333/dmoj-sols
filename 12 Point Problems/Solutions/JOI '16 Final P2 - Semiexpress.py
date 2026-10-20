import heapq

n, m, k = map(int, input().split())
a, b, c = map(int, input().split())
t = int(input())
s = [int(input()) for _ in range(m)]

tot = 0
h = []

def nxt(i, r):
    p = r + 1
    e = s[i + 1] - 1
    if p > e: return
    tp = b * (s[i] - 1) + c * (p - s[i])
    if tp > t: return
    g = min(e, p + (t - tp) // a) - p + 1
    heapq.heappush(h, (-g, i, p + g - 1))

for i in range(m - 1):
    t0 = b * (s[i] - 1)
    if t0 > t: continue
    r = min(s[i + 1] - 1, s[i] + (t - t0) // a)
    tot += r - s[i] + 1
    nxt(i, r)

if b * (n - 1) <= t: tot += 1
tot -= 1

for _ in range(k - m):
    if not h: break
    g, i, r = heapq.heappop(h)
    tot += -g
    nxt(i, r)

print(tot)