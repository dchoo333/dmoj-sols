numbers = [float(input()) for _ in range(int(input()))]
max_value = max(numbers)
numbers.remove(max_value)
numbers.append(max_value)
print('\n'.join("{:.2f}".format(number) for number in numbers))
