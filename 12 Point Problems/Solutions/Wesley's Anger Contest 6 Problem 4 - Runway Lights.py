n, k = map(int, input().split())
s = input().strip()
M = 998244353

w = a = c = wa = ac = wac = 0
for ch in s:
    if ch == 'W': w += 1
    elif ch == 'A': a += 1; wa += w
    elif ch == 'C': c += 1; ac += a; wac += wa

k2 = k * (k - 1) // 2
k3 = k * (k - 1) * (k - 2) // 6
print((k * wac + (wa * c + w * ac) * k2 + w * a * c * k3) % M)