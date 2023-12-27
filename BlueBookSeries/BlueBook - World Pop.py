def estimate_pop_growth(rate, start_year, initial_population, target_year):
    years_passed = target_year - start_year
    estimated_population = initial_population * (1 + rate / 100) ** years_passed
    return round(estimated_population)

rate = float(input())
start_year = int(input())
initial_population = int(input())
target_year = int(input())
estimated_population = estimate_pop_growth(rate, start_year, initial_population, target_year)
print(estimated_population)
