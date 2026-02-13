n = input()
while n != '99999':
    a, b = int(n[0]), int(n[1])
    others = n[2:]
    if a + b == 0:
        dir = ans
    elif (a + b) % 2 == 0:
        dir = 'right'
    else:
        dir = 'left'
    ans = dir
    print(dir, ''.join(others))
    n = input()
