for _ in range(int(input())):
    N = int(input())
    print(38 if N <= 30 else 55 if N <= 50 else 73 if N <= 100 else 73 + ((N - 100 - 1) // 50 + 1) * 24)
