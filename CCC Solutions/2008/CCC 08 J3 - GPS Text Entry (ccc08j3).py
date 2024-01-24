s = input()
newr = 0
newc = 0
movements = 0
r = 1
c = 1
for i in range(len(s)):
    letter = s[i]
    if 'A' <= letter <= 'Z':
        x = ord(letter) - ord('A') + 1
        newr = (x - 1) // 6 + 1
        newc = (x - 1) % 6 + 1
    elif letter == ' ':
        newr = 5
        newc = 3
    elif letter == '-':
        newr = 5
        newc = 4
    elif letter == '.':
        newr = 5
        newc = 5
    movements = movements + abs(newr - r) + abs(newc - c)
    r = newr
    c = newc
movements = movements + abs(newr - 5) + abs(newc - 6)
print(movements)
