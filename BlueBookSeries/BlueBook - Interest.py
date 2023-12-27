def calculate_amount(N, M, Y): return [(year, round(N * (1 + M / 100) ** year, 2)) for year in range(Y + 1)]
N, M, Y = map(float, input().split())
output_result = calculate_amount(N, M, int(Y))
for year, amount in output_result:
    print(f"{year} {amount:.2f}")
