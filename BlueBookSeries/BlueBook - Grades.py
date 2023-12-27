def calculate_grade(percentage):
    if 80 <= percentage <= 100: return 'A'
    elif 70 <= percentage <= 79: return 'B'
    elif 60 <= percentage <= 69: return 'C'
    elif 50 <= percentage <= 59: return 'D'
    elif 0 <= percentage <= 49: return 'F'
    else: return 'X'

T = int(input())
grades = [int(input()) for _ in range(T)]

for grade in grades:
    print(calculate_grade(grade))
