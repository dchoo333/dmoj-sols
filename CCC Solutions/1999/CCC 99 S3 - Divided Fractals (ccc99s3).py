n = int(input())
for _ in range(n):
    m, r1, r2, c1, c2 = [int(input()) for _ in range(5)]

    for i in range(r2, r1 - 1, -1):
        r = []
        for j in range(c1, c2 + 1):
            x = i - 1
            y = j - 1
            filled = True
            while x > 0 or y > 0:
                if x % 3 == 1 and y % 3 == 1:
                    filled = False
                    break
                x //= 3
                y //= 3
            r.append('*' if filled else ' ')
        print(' '.join(r))
    print()
