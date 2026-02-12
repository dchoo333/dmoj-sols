J = int(input())
vc = 0
for player1 in range(1, J):
    for player2 in range(player1 + 1, J):
        for player3 in range(player2 + 1, J):
            vc += 1
print(vc)