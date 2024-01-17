def int_to_roman(num):
    values = [
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    ]
    numerals = [
        'M', 'CM', 'D', 'CD',
        'C', 'XC', 'L', 'XL',
        'X', 'IX', 'V', 'IV',
        'I'
    ]

    result = ""
    for i in range(len(values)):
        while num >= values[i]:
            result += numerals[i]
            num -= values[i]

    return result

def roman_to_int(roman):
    values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    total = 0
    prev_value = 0

    try:
        for numeral in reversed(roman.upper()):
            value = values[numeral]
            if value < prev_value:
                total -= value
            else:
                total += value
            prev_value = value

        if total <= 0 or total > 1000:
            raise ValueError

        return total
    except (KeyError, ValueError):
        return "CONCORDIA CUM VERITATE"

def roman_calculator(test_cases):
    def add_roman_numerals(roman1, roman2):
        result = roman_to_int(roman1) + roman_to_int(roman2)
        if result <= 0 or result > 1000:
            return "CONCORDIA CUM VERITATE"
        return int_to_roman(result)

    results = []
    for test_case in test_cases:
        parts = test_case.strip().split('+')
        if len(parts) == 2 and parts[1].endswith('='):
            roman1 = parts[0]
            roman2 = parts[1][:-1]
            result = add_roman_numerals(roman1, roman2)
            results.append(f"{test_case}{result}")

    return results

cases = []
for i in range(int(input())):
    cases.append(input())
    
for res in roman_calculator(cases):
    print(res)
