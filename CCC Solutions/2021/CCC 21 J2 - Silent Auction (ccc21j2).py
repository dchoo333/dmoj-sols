n = int(input())
w = 0
res = ''
for _ in range(n):
    name = input()
    t = int(input())
    if t > w:
        w = t
        res = name
print(res)
