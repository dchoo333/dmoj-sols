dad, mom = input(), input()
possible = []
get = 0
for i in range(10):
    x, x2 = dad[i] + mom[get], dad[i] + mom[get + 1]
    possible.append(min(x[0], x[1]))
    possible.append(min(x2[0], x2[1]))
    if i % 2 == 1: get += 2
for i in range(int(input())):
    baby, isBaby = input(), True
    for j in baby:
        if j not in possible:
            isBaby = False
            break
    print('Possible baby.') if isBaby else print('Not their baby!')