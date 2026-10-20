a = [input().split() for _ in range(3)]

while True:
    done = all(c != 'X' for r in a for c in r)
    if done:
        break

    fixed = False
    for i in range(3):
        row = a[i]
        if row.count('X') == 1:
            idx = row.index('X')
            if idx == 0:
                row[0] = str(int(row[1])*2 - int(row[2]))
            elif idx == 1:
                row[1] = str((int(row[0]) + int(row[2]))//2)
            else:
                row[2] = str(int(row[1])*2 - int(row[0]))
            fixed = True

        col = [a[0][i], a[1][i], a[2][i]]
        if col.count('X') == 1:
            idx = col.index('X')
            if idx == 0:
                a[0][i] = str(int(col[1])*2 - int(col[2]))
            elif idx == 1:
                a[1][i] = str((int(col[0]) + int(col[2]))//2)
            else:
                a[2][i] = str(int(col[1])*2 - int(col[0]))
            fixed = True

    if not fixed:
        for r in [1,0,2,1,1,0,0,2,2,2]:
            for c in [1,1,1,0,2,0,2,0,0,2]:
                if a[r][c] == 'X':
                    a[r][c] = '0'
                    fixed = True
                    break
            if fixed:
                break

for r in a:
    print(' '.join(r))