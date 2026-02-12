l = str(input())
g = int(l.count(':-)'))
s = int(l.count(':-('))

if g > s:
    print('happy')
elif s > g:
    print('sad')
elif s == 0 or g == 0:
    print('none')
elif s == g:
    print('unsure')