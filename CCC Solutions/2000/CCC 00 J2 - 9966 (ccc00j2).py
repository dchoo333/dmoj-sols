valid_pairs = {(0, 0), (1, 1), (8, 8), (9, 6), (6, 9)}
def rotatability(num):
    a = [0] * 7
    works = True
    i = 0
    while num != 0:
        i += 1
        a[i] = num % 10
        num = num // 10
    for j in range(1, i + 1):
        if not (a[j], a[i - j + 1]) in valid_pairs:
            works = False
    return works

n = int(input())
m = int(input())
count = 0
for i in range(n, m + 1):
    if rotatability(i):
        count += 1
print(count)