o, n = map(int, input().split())

print('Sun Mon Tue Wed Thr Fri Sat')

rs = [[-1] * (o - 1)]
for i in range(1, n + 1):
    if len(rs[-1]) == 7:
        rs.append([])
    rs[-1].append(i)

print('\n'.join([' '.join([str(day).rjust(3) if day != -1 else '   ' for day in r]) for r in rs]))
