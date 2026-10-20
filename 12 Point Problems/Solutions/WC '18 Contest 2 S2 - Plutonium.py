import sys
D = sys.stdin.buffer.read().split()
n = int(D[0])
O = [int(x) for x in D[1:1 + n]]

c = 0; f1 = 0; fr = 0; ok = True
for i in range(n - 1, -1, -1):
    if O[i]:
        if c and c != O[i]: ok = False; break
        c = O[i]
    if i == 0:
        if c > 1: ok = False
        break
    if c == 1: f1 += 1
    elif c == 0: fr += 1
    if c: c -= 1

print(f"{f1} {f1 + fr}" if ok else -1)