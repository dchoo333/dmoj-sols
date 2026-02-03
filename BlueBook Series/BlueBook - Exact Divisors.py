number = int(input())
print('\n'.join(map(str, [divisor for divisor in range(1, number + 1) if number % divisor == 0])))