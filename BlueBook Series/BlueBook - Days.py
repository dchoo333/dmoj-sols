for _ in range(int(input())):
    Y, M, D = map(int, input().split())
    print(sum([31, 29 if ((Y % 4 == 0 and Y % 100 != 0) or (Y % 400 == 0)) else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31][:M-1]) + D)
