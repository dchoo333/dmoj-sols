import math

w = float(input())
h = float(input())
i0 = float(input())
b1 = float(input())

m = b1 / (w - i0)
c = -m * i0

for i in range(1, 1000000):
    y = m * (i * w) + c
    x = ((i * h) - c) / m

    yh = math.floor(y / h)
    xw = math.floor(x / w)

    ah = y - h * yh
    aw = x - w * xw

    if ah < 5 or h - ah < 5:
        if h * yh != y:
            ans = i - 1 + int(y / h)
        else:
            ans = i - 2 + int(y / h)
        print(ans)
        break

    if aw < 5 or w - aw < 5:
        if w * xw != x:
            ans = i - 1 + int(x / w)
        else:
            ans = i - 2 + int(x / w)
        print(ans)
        break
else:
    print(0)
