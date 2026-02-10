a = ["A","B","C","D","E"]

while 1:
    x = int(input())
    y = int(input())
    if x == 4 and y == 1:
        break
    if x == 1:
        y %= 5
        a = a[y:] + a[:y]
    elif x == 2:
        y %= 5
        a = a[-y:] + a[:-y]
    else:
        for _ in range(y):
            a[0], a[1] = a[1], a[0]

print(*a)
