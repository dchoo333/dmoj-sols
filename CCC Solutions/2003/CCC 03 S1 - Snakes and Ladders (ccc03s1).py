s = 1
jmp = {9:34, 54:19, 40:64, 90:48, 67:86, 99:77}

for _ in range(1000000):
    n = int(input())
    if n == 0:
        print("You Quit!")
        break

    nx = s + n

    if nx == 100:
        print("You are now on square 100")
        print("You Win!")
        break
    if nx > 100:
        print(f"You are now on square {s}")
        continue

    s = jmp.get(nx, nx)
    print(f"You are now on square {s}")
