def is_leap_year(year):
    return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

for _ in range(int(input())):
    Y, M, D = map(int, input().split())
    print(sum([31, 29 if is_leap_year(Y) else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31][:M-1]) + D)

