r, c = map(int, input().split())
board = [[1]*c] + [[-1]*c for _ in range(r-1)]
for i in range(r):
    board[i][0] = 1

for _ in range(int(input())):
    cr, cc = map(int, input().split())
    if cr == 1:
        for j in range(cc-1, c):
            board[0][j] = 0
    if cc == 1:
        for i in range(cr-1, r):
            board[i][0] = 0
    board[cr-1][cc-1] = 0

for i in range(1, r):
    for j in range(1, c):
        if board[i][j] != 0:
            board[i][j] = board[i-1][j] + board[i][j-1]

print(board[-1][-1])
