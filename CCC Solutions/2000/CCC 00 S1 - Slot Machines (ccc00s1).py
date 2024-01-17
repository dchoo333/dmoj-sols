quarters, first, second, third = map(int, [input() for _ in range(4)])
plays = 0

while quarters >= 1:
    machine = plays % 3
    quarters -= 1

    if machine == 0:
        first += 1
        quarters += 30 * (first % 35 == 0)
    elif machine == 1:
        second += 1
        quarters += 60 * (second % 100 == 0)
    elif machine == 2:
        third += 1
        quarters += 9 * (third % 10 == 0)

    plays += 1

print(f'Martha plays {plays} times before going broke.')