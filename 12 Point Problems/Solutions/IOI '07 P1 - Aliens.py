import sys

n, x0, y0 = map(int, input().split())

def ex(x, y):
    if not (1 <= x <= n and 1 <= y <= n): return False
    print(f"examine {x} {y}", flush=True)
    r = input().strip()
    if r == "-1": sys.exit()
    return r == "true"

def edge(dx, dy):
    lo, d = 0, 1
    while ex(x0 + dx * d, y0 + dy * d):
        lo = d; d *= 2
    hi = d
    while hi - lo > 1:
        md = (lo + hi) // 2
        if ex(x0 + dx * md, y0 + dy * md): lo = md
        else: hi = md
    return lo

R = x0 + edge(1, 0)
L = x0 - edge(-1, 0)
B = y0 - edge(0, -1)

w = R - L + 1
M = w
for k in (5, 3):
    if w % k == 0:
        m = w // k
        if m % 2 and not ex(L + m, y0):
            M = m; break

def cnt(dx, dy):
    c, x, y = 0, L + dx, B + dy
    while ex(x, y):
        c += 1; x += dx; y += dy
    return c

a = cnt(-2 * M, 0); b = cnt(2 * M, 0)
c = cnt(0, -2 * M); d = cnt(0, 2 * M)
col = 2 * a + 1 if a + b == 2 else 2 * a + 2
row = 2 * c + 1 if c + d == 2 else 2 * c + 2

h = (M - 1) // 2
print(f"solution {L + (3 - col) * M + h} {B + (3 - row) * M + h}", flush=True)