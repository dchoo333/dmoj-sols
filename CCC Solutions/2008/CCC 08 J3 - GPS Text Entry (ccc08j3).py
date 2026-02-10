s = input()

r = c = 1
ans = 0

for ch in s:
    if 'A' <= ch <= 'Z':
        x = ord(ch) - 65
        nr = x // 6 + 1
        nc = x % 6 + 1
    elif ch == ' ':
        nr, nc = 5, 3
    elif ch == '-':
        nr, nc = 5, 4
    else:
        nr, nc = 5, 5

    ans += abs(nr - r) + abs(nc - c)
    r, c = nr, nc

ans += abs(r - 5) + abs(c - 6)
print(ans)
