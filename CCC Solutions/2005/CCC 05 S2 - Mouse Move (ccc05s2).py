c, r = map(int, input().split())
x, y = 0, 0

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    if x + a < 0:
        x = 0
    elif x + a > c:
        x = c
    else:
        x += a
    if y + b < 0:
        y = 0
    elif y + b > r:
        y = r
    else:
        y += b
    print(x, y)