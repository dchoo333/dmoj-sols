w = input()
cs = {char: w.count(char) for char in 'IOSHZXN'}
print('YES' if sum(cs.values()) == len(w) else 'NO')
