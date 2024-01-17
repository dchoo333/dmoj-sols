def calculate_rounds(undefeated):
    round_count, oneloss, eliminated = 0, 0, 0

    while True:
        if round_count == 0:
            print(f"Round {round_count}: {undefeated} undefeated, {oneloss} one-loss, {eliminated} eliminated")
        else:
            if undefeated == 1 and oneloss == 0 and eliminated == 0:
                break
            elif undefeated == 1 and oneloss % 2 == 0:
                eliminated += oneloss // 2
                oneloss -= oneloss // 2
            elif undefeated == 1 and oneloss == 1:
                undefeated = 0
                oneloss = 2
            else:
                eliminated += oneloss // 2
                oneloss -= oneloss // 2
                oneloss += undefeated // 2
                undefeated -= undefeated // 2

            print(f"Round {round_count}: {undefeated} undefeated, {oneloss} one-loss, {eliminated} eliminated")

            if oneloss == 1 and undefeated == 0:
                break

        round_count += 1

    return round_count

N = int(input())
test_cases = []

for _ in range(N):
    undefeated = int(input())
    test_cases.append(undefeated)

for i, undefeated in enumerate(test_cases):
    rounds = calculate_rounds(undefeated)
    print(f"There are {rounds} rounds.")
        
    if i < N - 1:
        print()