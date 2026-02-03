n = int(input())
for _ in range(n):
    h = v = f = 0
    while True:
        m = int(input())
        if m == 0: break
        if m == 1:
            a = int(input())
            if f % 4 == 0: v += a
            elif f % 4 == 2: v -= a
            elif f % 4 == 3: h -= a
            elif f % 4 == 1: h += a
        elif m == 2: f += 1
        else: f -= 1

    t = abs(h) + abs(v)
    print(f"Distance is {t}")

    if t != 0:
        vg = 2 if v > 0 else 0 if v < 0 else -1
        hg = 3 if h > 0 else 1 if h < 0 else -1

        if h == 0:
            if v > 0:
                if f % 4 == 1: print(2); f += 1
                elif f % 4 == 3: print(3); f -= 1
                elif f % 4 == 0: print(2); print(2); f += 2
            elif v < 0:
                if f % 4 == 3: print(2); f += 1
                elif f % 4 == 1: print(3); f -= 1
                elif f % 4 == 2: print(2); print(2); f += 2
            print(1); print(abs(v))
        elif v == 0:
            # goH
            if h > 0:
                if f % 4 == 0: print(3); f -= 1
                elif f % 4 == 2: print(2); f += 1
                elif f % 4 == 1: print(2); print(2); f += 2
            elif h < 0:
                if f % 4 == 0: print(2); f += 1
                elif f % 4 == 2: print(3); f -= 1
                elif f % 4 == 3: print(2); print(2); f += 2
            print(1); print(abs(h))
        elif f % 2 == 0:
            if f % 4 == vg:
                if v > 0:
                    if f % 4 == 1: print(2); f += 1
                    elif f % 4 == 3: print(3); f -= 1
                    elif f % 4 == 0: print(2); print(2); f += 2
                elif v < 0:
                    if f % 4 == 3: print(2); f += 1
                    elif f % 4 == 1: print(3); f -= 1
                    elif f % 4 == 2: print(2); print(2); f += 2
                print(1); print(abs(v))
                if h > 0:
                    if f % 4 == 0: print(3); f -= 1
                    elif f % 4 == 2: print(2); f += 1
                    elif f % 4 == 1: print(2); print(2); f += 2
                elif h < 0:
                    if f % 4 == 0: print(2); f += 1
                    elif f % 4 == 2: print(3); f -= 1
                    elif f % 4 == 3: print(2); print(2); f += 2
                print(1); print(abs(h))
            else:
                if h > 0:
                    if f % 4 == 0: print(3); f -= 1
                    elif f % 4 == 2: print(2); f += 1
                    elif f % 4 == 1: print(2); print(2); f += 2
                elif h < 0:
                    if f % 4 == 0: print(2); f += 1
                    elif f % 4 == 2: print(3); f -= 1
                    elif f % 4 == 3: print(2); print(2); f += 2
                print(1); print(abs(h))
                if v > 0:
                    if f % 4 == 1: print(2); f += 1
                    elif f % 4 == 3: print(3); f -= 1
                    elif f % 4 == 0: print(2); print(2); f += 2
                elif v < 0:
                    if f % 4 == 3: print(2); f += 1
                    elif f % 4 == 1: print(3); f -= 1
                    elif f % 4 == 2: print(2); print(2); f += 2
                print(1); print(abs(v))
        else:
            if f % 4 == hg:
                if h > 0:
                    if f % 4 == 0: print(3); f -= 1
                    elif f % 4 == 2: print(2); f += 1
                    elif f % 4 == 1: print(2); print(2); f += 2
                elif h < 0:
                    if f % 4 == 0: print(2); f += 1
                    elif f % 4 == 2: print(3); f -= 1
                    elif f % 4 == 3: print(2); print(2); f += 2
                print(1); print(abs(h))
                if v > 0:
                    if f % 4 == 1: print(2); f += 1
                    elif f % 4 == 3: print(3); f -= 1
                    elif f % 4 == 0: print(2); print(2); f += 2
                elif v < 0:
                    if f % 4 == 3: print(2); f += 1
                    elif f % 4 == 1: print(3); f -= 1
                    elif f % 4 == 2: print(2); print(2); f += 2
                print(1); print(abs(v))
            else:
                if v > 0:
                    if f % 4 == 1: print(2); f += 1
                    elif f % 4 == 3: print(3); f -= 1
                    elif f % 4 == 0: print(2); print(2); f += 2
                elif v < 0:
                    if f % 4 == 3: print(2); f += 1
                    elif f % 4 == 1: print(3); f -= 1
                    elif f % 4 == 2: print(2); print(2); f += 2
                print(1); print(abs(v))
                if h > 0:
                    if f % 4 == 0: print(3); f -= 1
                    elif f % 4 == 2: print(2); f += 1
                    elif f % 4 == 1: print(2); print(2); f += 2
                elif h < 0:
                    if f % 4 == 0: print(2); f += 1
                    elif f % 4 == 2: print(3); f -= 1
                    elif f % 4 == 3: print(2); print(2); f += 2
                print(1); print(abs(h))
