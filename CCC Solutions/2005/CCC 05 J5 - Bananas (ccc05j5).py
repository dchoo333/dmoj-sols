A = 0
while True:
    BANANAS = input()
    if BANANAS == 'X': 
      break
    new_thing = BANANAS.replace('B', '(').replace('S', ')').replace('N', '+')
    try:
        eval(new_thing)
        if '()' in new_thing:
            raise ValueError
        if '(' in BANANAS or ')' in BANANAS or '+' in BANANAS:
            raise ValueError
        print('YES')
    except Exception:
        print('NO')