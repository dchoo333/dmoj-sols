k = int(input())
a = input().strip()
for i in range(len(a)):
    s = 3 * (i + 1) + k
    c = a[i]
    a1 = ord(c) - s
    if a1 < 65:
        a1 = a1 + 26
    n = chr(a1)
    print(n, end="")