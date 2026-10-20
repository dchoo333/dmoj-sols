import sys
D = sys.stdin.buffer.read().split()
n, k = int(D[0]), int(D[1])
P = [0] + [int(x) for x in D[2:2 + 2 * n:2]]
F = [0] + [int(x) for x in D[3:3 + 2 * n:2]]
F[n] = 1

if sum(F) > k: print("DEA Bust!"); sys.exit()

nm = [n] * (n + 2)
for i in range(n, 0, -1): nm[i] = i if F[i] else nm[i + 1]

def ok(c):
    cur = j = s = 0
    while cur < n:
        while j < n and P[j + 1] - P[cur] <= c: j += 1
        if j == cur: return False
        m = nm[cur + 1]
        cur = m if m <= j else j
        s += 1
        if s > k: return False
    return True

lo = max(P[i + 1] - P[i] for i in range(n))
hi = P[n]
while lo < hi:
    md = (lo + hi) // 2
    if ok(md): hi = md
    else: lo = md + 1

print(lo)