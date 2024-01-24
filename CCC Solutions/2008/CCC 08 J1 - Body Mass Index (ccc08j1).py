weight = float(input())
height = float(input())
hs = height * height
thing = weight / hs
if thing > 25:
    print('Overweight')
elif thing < 18.5:
    print('Underweight')
else:
    print('Normal weight')

