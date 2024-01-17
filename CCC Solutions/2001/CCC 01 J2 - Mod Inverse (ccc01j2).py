a, b, n = int(input()), int(input()), True

for x in range(1000):
    if (a * x - 1) % b == 0:
        print(x)
        n = False
        break

print("No such integer exists.") if n else ''
