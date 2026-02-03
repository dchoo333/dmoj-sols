v = {(0,0),(1,1),(8,8),(6,9),(9,6)}
n = int(input())
m = int(input())
c = 0
for x in range(n, m+1):
    a = []
    y = x
    while y > 0:
        a.append(y % 10)
        y //= 10
    if all((a[i], a[-i-1]) in v for i in range(len(a))):
        c += 1
print(c)
