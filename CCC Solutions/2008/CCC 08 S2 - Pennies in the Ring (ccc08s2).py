import math

while True:
    r = int(input())
    if r == 0:
        break
    cnt = 0
    for i in range(r + 1):
        cnt += int(math.sqrt(r * r - i * i))
    print(cnt * 4 + 1)
