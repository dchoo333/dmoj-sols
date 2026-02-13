n, l = map(int, input().split())

for _ in range(n):
    s = input()
    prv = s.count(s[0]) > 1
    valid = True
    for i in range(1, len(s)):
        if prv + (s.count(s[i]) > 1) != 1:
            valid = False
            break
        prv = not prv
    print('T' if valid else 'F')
