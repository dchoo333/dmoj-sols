rivers = []
n = int(input())

for i in range(n):
    rivers.append(float(input()))

while True:
    op = int(input())
    if op == 77:
        break
    if op == 99:
        index = int(input()) - 1
        percent = float(input())
        rivers.insert(index + 1, rivers[index] * (100 - percent) / 100.0)
        rivers[index] = rivers[index] * (percent / 100.0)
    if op == 88:
        index = int(input()) - 1
        rivers[index] = rivers[index] + rivers[index + 1]
        rivers.pop(index + 1)

for d in rivers:
    print(round(d), end=" ")
