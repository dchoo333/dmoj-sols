n = int(input())
s = []
for _ in range(n):
    x, y = [float(input()) for _ in range(2)]
    s.append([x, y, [0.0, 1000.0]])

for i in range(n):
    xi, yi = s[i][0], s[i][1]
    li, ri = s[i][2]
    for j in range(n):
        if i == j:
            continue
        xj, yj = s[j][0], s[j][1]
        A = 2 * (xj - xi)
        B = xi**2 - xj**2 + yi**2 - yj**2
        if abs(A) < 1e-8:
            if B > 1e-8:
                li, ri = 1.0, 0.0
                break
            continue
        x0 = -B / A
        if A > 0:
            ri = min(ri, x0)
        else:
            li = max(li, x0)
        if li - ri > 1e-8:
            break
    s[i][2] = [li, ri]

for si in s:
    li, ri = si[2]
    li = max(li, 0.0)
    ri = min(ri, 1000.0)
    if ri - li >= -1e-8:
        print(f"The sheep at ({int(si[0])}, {int(si[1])}) might be eaten.")
