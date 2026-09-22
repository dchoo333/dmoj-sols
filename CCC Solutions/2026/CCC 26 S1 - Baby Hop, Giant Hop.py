S, E, G, T = [int(input()) for _ in range(4)]

D = abs(E - S)

if D == 0:
    print(0 if T == 1 else 2)
else:
    a = D // G
    r = D % G

    m1 = min(a + r, a + 1 + (G - r if r else G))

    if T == 1:
        print(m1)
    else:
        ach = False

        if G > 1:
            num = D - m1 - 1
            if num >= 0 and num % (G - 1) == 0:
                kc = num // (G - 1)
                if kc <= a:
                    ach = True

        if not ach:
            num = D + m1 + 1
            if num % (G + 1) == 0:
                if num // (G + 1) >= a + 1:
                    ach = True

        print(m1 + (1 if ach else 2))
