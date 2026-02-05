a, b = [int(input()) for _ in range(2)]

for x in range(1000):
    if (a*x - 1) % b == 0:
        print(x)
        break
else:
    print("No such integer exists.")
