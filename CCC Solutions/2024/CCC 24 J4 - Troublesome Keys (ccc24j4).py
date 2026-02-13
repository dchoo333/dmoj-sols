from itertools import permutations
s = input()
got = input()
alpha = 'abcdefghijklmnopqrstuvwxyz'

if len(s) == len(got):
    for i, (s, g) in enumerate(zip(s, got)):
        if s != g:
            a, b, c = s, g, '-'
            break
else:
    diff = [ch for ch in alpha if got.count(ch) != s.count(ch)]
    for p in permutations(diff):
        x = s.replace(p[0], p[1])
        if p[2] in x:
            y = x.replace(p[2], '')
            if y == got:
                a, b, c = p
                break

print(a, b)
print(c)
