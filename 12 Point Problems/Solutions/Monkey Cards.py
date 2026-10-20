n, k = map(int, input().split())
a = sorted(map(int, input().split()))
b = sorted(map(int, input().split()))

la, lb = a[:k], b[n - k:]
ha, hb = a[k:], b[:n - k]

oa, ob = [], []
s = 0

ua, ub = [], []
j = 0
for x in lb:
    if j < k and la[j] < x:
        oa.append(la[j]); ob.append(x); s += 1; j += 1
    else: ub.append(x)
ua = la[j:]
oa += ua; ob += ub

ua, ub = [], []
j = 0
m = n - k
for x in ha:
    if j < m and x > hb[j]:
        oa.append(x); ob.append(hb[j]); s += 1; j += 1
    else: ua.append(x)
ub = hb[j:]
oa += ua; ob += ub

print(s)
print(" ".join(map(str, oa)))
print(" ".join(map(str, ob)))