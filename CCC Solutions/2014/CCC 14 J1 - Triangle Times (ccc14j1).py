a, b, c,  = int(input()), int(input()), int(input())
if a == b == c == 60:
    print('Equilateral')
elif a + b + c != 180 or any(side == 0 for side in (a, b, c)) or a + b + c > 180:
    print('Error')
elif a == b or b == c or a == c:
    print('Isosceles')
else:
    print('Scalene')