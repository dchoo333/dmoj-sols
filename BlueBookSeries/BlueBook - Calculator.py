def convert_base_n_to_decimal(number, base):
    n, conversion, q = 0, 0, number
    while q != 0:
        digit = number % 10
        q = number // 10
        conversion += digit * base**n
        n += 1
        number = q
    return conversion

def convert_decimal_to_final_base(number, base):
    sum_of_numbers, s = 0, 1
    while number != 0:
        remainder = number % base
        sum_of_numbers += remainder * s
        s *= 10
        number //= base
    return sum_of_numbers

cases = int(input())
for i in range(cases):
    base1 = int(input())
    number1 = int(input())
    base2 = int(input())
    number2 = int(input())
    operand = str(input())
    final_base = int(input())

    decimal1 = convert_base_n_to_decimal(number1, base1)
    decimal2 = convert_base_n_to_decimal(number2, base2)

    if operand == "+":
        result = decimal1 + decimal2
    elif operand == "-":
        result = decimal1 - decimal2
    elif operand == "*":
        result = decimal1 * decimal2
    else:
        result = decimal1 // decimal2

    final_result = convert_decimal_to_final_base(result, final_base)
    print(final_result)

    if i != cases - 1:
        spaces = input()
