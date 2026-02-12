a = int(input())
for i in range(a):
    for l in range(a):
        print("*", end="")
    for j in range(a):
        print("x", end="")
    for k in range(a):
        print("*", end="")
    print()
for i in range(a):
    for j in range(a):
        print(" ", end="")
    for k in range(a*2):
        print("x", end="")
    print()
for i in range(a):
    for j in range(a):
        print("*", end="")
    for k in range(a):
        print(" ", end="")
    for l in range(a):
        print("*", end="")
    print()