import sys

n, k = map(int, input().split())
h = n // 2
w = sys.stdout.write
first = True

def out(r):
    global first
    r = iter(r)
    while True:
        c = []
        for x in r:
            c.append(x)
            if len(c) == 4096: break
        if not c: return
        w(('' if first else ' ') + ' '.join(map(str, c)))
        first = False

if k <= h:
    out(range(n, n - k, -1))
    out(range(k + 1, n - k + 1))
    out(range(k, 0, -1))
else:
    t = k - h + 1
    out(range(n, t, -1))
    out(range(t - 1, 0, -1))
    out((t,))
w('\n')