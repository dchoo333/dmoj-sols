P = set()
while True:
    s = input().strip()
    if s == '.': break
    P.update(s.split())

ls = []
while True:
    try: ls.append(input().strip())
    except EOFError: break
S = ''.join(ls)

n = len(S)
lens = sorted({len(p) for p in P})
ok = bytearray(n + 1)
ok[0] = 1
best = 0
for i in range(n + 1):
    if not ok[i]: continue
    best = i
    for L in lens:
        if i + L > n: break
        if S[i:i + L] in P: ok[i + L] = 1

print(best)