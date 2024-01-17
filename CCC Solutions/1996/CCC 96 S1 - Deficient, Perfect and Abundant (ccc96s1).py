def factors_of(number):
    return [whole_number for whole_number in range(1, number) if number % whole_number == 0]

for _ in range(int(input())):
    n = int(input())
    nums = factors_of(n)
    result = "a deficient" if sum(nums) < n else "a perfect" if sum(nums) == n else "an abundant"
    print(f'{n} is {result} number.')

