d = int(input())
h, m = 12, -1
c = 31 * (d // 720)
d %= 720

for i in range(d + 1):
    m += 1
    if m == 60:
        m = 0
        h += 1
        if h == 13:
            h = 1
    if m < 10 or h == 10:
        continue
    if h < 10 and (m % 10 - m // 10 == m // 10 - h % 10):
        c += 1
    elif h > 10 and (m % 10 - m // 10 == m // 10 - h % 10 == h % 10 - h // 10):
        c += 1

print(c)
