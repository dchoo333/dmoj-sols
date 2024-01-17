import sys

spiral = [[0 for i in range(10)] for j in range(10)]
rCur, cCur, n, start, end = 4, 4, 0, 0, 0

def downRight(k, cnt):
    global rCur, cCur
    for i in range(k):
        rCur += 1
        cnt += 1
        spiral[rCur][cCur] = cnt
        if cnt == end:
            return
    for i in range(k):
        cCur += 1
        cnt += 1
        spiral[rCur][cCur] = cnt
        if cnt == end:
            return
    upLeft(k + 1, cnt)
    
def upLeft(k, cnt):
    global rCur, cCur
    for i in range(k):
        rCur -= 1
        cnt += 1
        spiral[rCur][cCur] = cnt
        if cnt == end:
            return
    for i in range(k):
        cCur -= 1
        cnt += 1
        spiral[rCur][cCur] = cnt
        if cnt == end:
            return
    downRight(k + 1, cnt)

start = int(input())
end = int(input())

if start == end:
    print(start)
else:
    rCur, cCur = 4, 4
    spiral[rCur][cCur] = start
    k = 1
    cnt = start
    downRight(k, cnt)
    for i in range(10):
        for j in range(10):
            if spiral[i][j] == 0:
                print("   ", end="")
            else:
                print(spiral[i][j], end=" ")
        print()
