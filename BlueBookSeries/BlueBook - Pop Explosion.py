P, A, Y, B = map(float, input().split())
while A < B: A, Y = A * (1 + P / 100), Y + 1
print(int(Y))
