# simple coordinate tracking algo
m = int(input())
x, y = 0, 0
done = set()
done.add((x, y))
rc = 0
for _ in range(m):
    info = input()
    d = info[0]
    dx, dy = 0, 0
    if d == 'N':
        dy = 1
    elif d == 'S':
        dy = -1
    elif d == 'E':
        dx = 1
    elif d == 'W':
        dx = -1
    for _ in range(int(info[1:])):
        x += dx
        y += dy
        if (x, y) in done:
            rc += 1
        done.add((x, y))
print(rc)