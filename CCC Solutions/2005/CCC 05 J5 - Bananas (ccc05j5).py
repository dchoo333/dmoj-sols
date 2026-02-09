A = 0
while True:
    x = input()
    if x == 'X': 
      break
    dh = x.replace('B', '(').replace('S', ')').replace('N', '+')
    try:
        eval(dh)
        if '()' in dh:
            raise ValueError
        if '(' in x or ')' in x or '+' in x:
            raise ValueError
        print('YES')
    except Exception:
        print('NO')