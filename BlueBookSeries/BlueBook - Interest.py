def calculate_amount(N, M, Y):
    result = []

    for year in range(Y + 1):
        amount = N * (1 + M / 100) ** year
        result.append((year, round(amount, 2)))

    return result

N, M, Y = map(float, input().split())
output_result = calculate_amount(N, M, int(Y))
for year, amount in output_result:
    print(f"{year} {amount:.2f}")
