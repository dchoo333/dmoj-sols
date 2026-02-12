n = int(input(''))
a, d = 100, 100
for i in range(n):
    ar, dr = map(int, input().split())
    if ar > dr:
        d = d - ar
    elif ar < dr:
        a = a - dr
    else:
        pass
print(a)
print(d)