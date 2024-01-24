n = int(input())
    
x = [0] * n
y = [0] * n
z = [0] * n
for i in range(n):
    year, month, day = map(int, input().split())
    if 2007 - year > 18:
        print("Yes")
    elif 2007 - year <= 17:
        print("No")
    elif month > 2:
        print("No")
    elif month == 1:
        print("Yes")
    elif day > 27:
        print("No")
    elif day <= 27:
        print("Yes")