U = 9999999

def r(a, b, c):
    return min(b, c) <= a <= max(b, c)

def b(rx, ry, jx, jy, ax, ay, bx, by):
    if rx == jx:
        m1, c1 = U, 0
    else:
        m1 = (ry - jy) / (rx - jx)
        c1 = ry - m1 * rx

    if ax == bx:
        m2, c2 = U, 0
    else:
        m2 = (ay - by) / (ax - bx)
        c2 = ay - m2 * ax

    if m1 == m2:
        if m1 != U:
            return c1 == c2 and (r(ax, rx, jx) or r(bx, rx, jx))
        else:
            return rx == ax and (r(ay, ry, jy) or r(by, ry, jy))

    if m1 != U and m2 != U:
        x = (c2 - c1) / (m1 - m2)
        y = m1 * x + c1
    elif m1 == U:
        x = rx
        y = m2 * x + c2
    else:
        x = ax
        y = m1 * x + c1

    return r(x, rx, jx) and r(y, ry, jy) and r(x, ax, bx) and r(y, ay, by)


rx, ry, jx, jy = map(int, input().split())
n = int(input())
ans = 0

for _ in range(n):
    d = list(map(int, input().split()))
    c = d[0]
    p = [(d[i], d[i+1]) for i in range(1, len(d), 2)]
    f = False
    for i in range(c):
        if b(rx, ry, jx, jy, p[i][0], p[i][1], p[(i+1) % c][0], p[(i+1) % c][1]):
            f = True
            break
    if f:
        ans += 1

print(ans)
