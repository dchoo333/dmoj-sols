t = input()

s = []
p = ''
n = ''
for i in t:
    if i in 'ABCDEFGHIJKLMNOPQRST' and p != '':
        print(''.join(s), p, n)
        s = []
        n = ''
        p = ''
        s.append(i)
    elif i in 'ABCDEFGHIJKLMNOPQRST':
        s.append(i)
    elif i == '+':
        p = 'tighten'
    elif i == '-':
        p = 'loosen'
    else:
        n = n + i

print(''.join(s), p, n)