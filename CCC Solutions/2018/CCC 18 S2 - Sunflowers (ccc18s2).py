n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

for _ in range(4):
    a = list(zip(*a[::-1]))
    ba = False
    rs = [r[0] for r in a]
    if rs != sorted(rs):
        continue
    for r in a:
        prev = 0
        for x in r:
            if x < prev:
                ba = True
                break
            prev = x
        if ba:
            break
    if not ba:
        for r in a:
            print(" ".join(map(str,r)))
        break
