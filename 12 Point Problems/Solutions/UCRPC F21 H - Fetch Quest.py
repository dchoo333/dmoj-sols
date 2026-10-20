import sys, heapq
sys.setrecursionlimit(10000)
D = sys.stdin.buffer.read().split()
n, m = int(D[0]), int(D[1])

g = [[] for _ in range(n)]
for i in range(m):
    u, v, w = int(D[2 + 3 * i]), int(D[3 + 3 * i]), int(D[4 + 3 * i])
    g[u].append((v, w)); g[v].append((u, w))

I = float('inf')
d = [I] * n
d[0] = 0
h = [(0, 0)]
while h:
    x, u = heapq.heappop(h)
    if x > d[u]: continue
    for v, w in g[u]:
        if x + w < d[v]:
            d[v] = x + w; heapq.heappush(h, (x + w, v))

W = sorted(d[1:], reverse=True)
k = len(W)
if not k: print(0); sys.exit()
if W[0] > 300: print("Impossible!"); sys.exit()
S = sum(W)
mn = W[-1]

def ok(C):
    sl = 4 * C - S
    if sl < 0: return False
    L = [0, 0, 0, 0]
    bad = set()

    def f(i, ws):
        if i == k: return True
        a, b, c, e = sorted(L)
        key = (((i * 512 + a) * 512 + b) * 512 + c) * 512 + e
        if key in bad: return False
        x = W[i]
        t = []
        for j in range(4):
            l = L[j]
            if l in t or l + x > C: continue
            t.append(l)
            L[j] = l + x
            nw = ws + (C - L[j] if L[j] + mn > C else 0)
            if nw <= sl and f(i + 1, nw): return True
            L[j] = l
        bad.add(key)
        return False

    return f(0, 0)

for C in range(max(W[0], (S + 3) // 4), 301):
    if ok(C): print(2 * C); sys.exit()
print("Impossible!")