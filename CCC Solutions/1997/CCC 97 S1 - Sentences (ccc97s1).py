for _ in range(int(input())):
    a,b,c = map(int,(input() for _ in range(3)))
    x = [input() for _ in range(a)]
    y = [input() for _ in range(b)]
    z = [input() for _ in range(c)]
    for i in x:
        for j in y:
            for k in z:
                print(f"{i} {j} {k}.")
