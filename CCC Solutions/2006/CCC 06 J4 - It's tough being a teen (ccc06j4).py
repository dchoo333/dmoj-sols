adj = [[0] * 10 for _ in range(10)]
cnt = [0] * 10

adj[1][7] = 1
adj[1][4] = 1
adj[2][1] = 1
adj[3][4] = 1
adj[3][5] = 1
cnt[7] = 1
cnt[4] = 2
cnt[1] = 1
cnt[5] = 1

while True:
    a = int(input())
    b = int(input())
    adj[a][b] = 1
    cnt[b] += 1
    if a == 0 or b == 0:
        break

index = 0
order = [0] * 10

for i in range(1, 8):
    for j in range(1, 8):
        if cnt[j] == 0:
            index += 1
            order[index] = j
            cnt[j] = -1
            for k in range(1, 8):
                if adj[j][k] == 1:
                    adj[j][k] = 0
                    cnt[k] -= 1
            break

if index < 7:
    print("Cannot complete these tasks. Going to bed.")
else:
    print(*order[1:-2])