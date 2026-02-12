a, b = input(''), input('')
result = 'A' if b.count('A') > b.count('B') else 'B' if b.count('B') > b.count('A') else 'Tie'
print(result)