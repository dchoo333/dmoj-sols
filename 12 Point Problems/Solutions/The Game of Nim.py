n = int(input())
a = [int(input()) for _ in range(n)]

def mv():
    x = 0
    for v in a: x ^= v
    for i in range(n):
        if a[i] ^ x < a[i]:
            t = a[i] - (a[i] ^ x)
            a[i] -= t
            print(i + 1, t, flush=True)
            return

x = 0
for v in a: x ^= v
if x: mv()
else: print(1, 0, flush=True)

while True:
    p, k = map(int, input().split())
    if p == 0: break
    a[p - 1] -= k
    mv()