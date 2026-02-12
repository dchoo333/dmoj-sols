T = int(input())
G = int(input())

score = [0] * 5
played = [[False]*5 for _ in range(5)]

for _ in range(G):
    a,b,sa,sb = map(int, input().split())
    played[a][b] = played[b][a] = True
    if sa > sb:
        score[a] += 3
    elif sa == sb:
        score[a] += 1
        score[b] += 1
    else:
        score[b] += 3

games = []
for i in range(1,5):
    for j in range(i+1,5):
        if not played[i][j]:
            games.append((i,j))

rem = len(games)
ans = 0

def dfs(res, idx=0):
    global ans
    if idx == rem:
        if all(score[T] > score[i] for i in range(1,5) if i != T):
            ans += 1
        return
    a,b = games[idx]
    if res == 'a':
        score[a] += 3
        dfs('a', idx+1)
        dfs('b', idx+1)
        dfs('t', idx+1)
        score[a] -= 3
    elif res == 'b':
        score[b] += 3
        dfs('a', idx+1)
        dfs('b', idx+1)
        dfs('t', idx+1)
        score[b] -= 3
    else:
        score[a] += 1
        score[b] += 1
        dfs('a', idx+1)
        dfs('b', idx+1)
        dfs('t', idx+1)
        score[a] -= 1
        score[b] -= 1

dfs('a')
dfs('b')
dfs('t')

print(ans//3)
