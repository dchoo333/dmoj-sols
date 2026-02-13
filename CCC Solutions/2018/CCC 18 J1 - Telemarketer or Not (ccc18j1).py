a, b, c, d = [int(input()) for _ in range(4)]
count = 0
if d == 8 or d == 9:
    count = count + 1
if c == b:
    count = count + 1
if a == 8 or a == 9:
    count = count + 1
if count == 3:
    print('ignore')
else:
    print('answer')
