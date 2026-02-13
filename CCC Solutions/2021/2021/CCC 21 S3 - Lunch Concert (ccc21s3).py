n = int(input())
p = []
s = []
r = []
for _ in range(n):
    a, b, c = map(int, input().split())
    p.append(a)
    s.append(b)
    r.append(c)

lo = 0
hi = int(1e9)
while lo <= hi:
    mid = (lo + hi) // 2
    m = sum(max(0, abs(p[i]-mid) - r[i]) * s[i] for i in range(n))
    l = sum(max(0, abs(p[i]-(mid-1)) - r[i]) * s[i] for i in range(n))
    r_ = sum(max(0, abs(p[i]-(mid+1)) - r[i]) * s[i] for i in range(n))
    if m == l or m == r_ or (m < l and m < r_):
        ans = m
        break
    if m < r_:
        hi = mid - 1
    else:
        lo = mid + 1

print(ans)
