def count_occurrences(input_list):
    ranges = {
        'A': range(0, 9999),
        'B': range(10000, 19999),
        'C': range(20000, 29999),
        'D': range(30000, 39999),
        'E': range(40000, 49999),
        'F': range(50000, 1000000)
    }

    counts = {'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0, 'F': 0}

    for num in input_list:
        if num == -1:
            break

        found = False
        for key, value in ranges.items():
            if num in value:
                counts[key] += 1
                found = True
                break

        if not found:
            counts['F'] += 1

    return counts

input_numbers = []
while True:
    num = int(input())
    if num == -1:
        break
    input_numbers.append(num)

result = count_occurrences(input_numbers)

for key in ['A', 'B', 'C', 'D', 'E', 'F']:
    print(result[key])
