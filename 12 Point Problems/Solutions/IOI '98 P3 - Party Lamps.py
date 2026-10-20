import sys

t = list(map(int, sys.stdin.read().split()))
n, c = t[0], t[1]
i = 2
on = []
while t[i] != -1: on.append(t[i]); i += 1
i += 1
off = []
while t[i] != -1: off.append(t[i]); i += 1

res = []
seen = set()
for m in range(16):
    p = bin(m).count('1')
    if p > c or (c - p) % 2: continue
    s = []
    for k in range(1, n + 1):
        v = 1
        if m & 1: v ^= 1
        if m & 2 and k % 2 == 1: v ^= 1
        if m & 4 and k % 2 == 0: v ^= 1
        if m & 8 and k % 3 == 1: v ^= 1
        s.append(v)
    if any(s[k - 1] != 1 for k in on) or any(s[k - 1] != 0 for k in off): continue
    st = ''.join(map(str, s))
    if st not in seen: seen.add(st); res.append(st)

print("\n".join(sorted(res)) if res else "IMPOSSIBLE")