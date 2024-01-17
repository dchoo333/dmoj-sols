burger_calories = [461, 431, 420, 0]
side_calories = [100, 57, 70, 0]
drink_calories = [130, 160, 118, 0]
dessert_calories = [167, 266, 75, 0]

burger = int(input())
side = int(input())
drink = int(input())
dessert = int(input())

count = burger_calories[burger - 1] + side_calories[side - 1] + drink_calories[drink - 1] + dessert_calories[dessert - 1]

print(f'Your total Calorie count is {count}.')
