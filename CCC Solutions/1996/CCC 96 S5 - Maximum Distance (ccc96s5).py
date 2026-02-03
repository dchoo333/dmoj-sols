n = int(input())

for _ in range(n):
    length = int(input())
    x_list = list(map(int, input().split()))
    y_list = list(map(int, input().split()))

    maximum = max((((z - y) if x_list[y] <= y_list[z] else 0) for y in range(length) for z in range(y, length)), default=0)

    print(f"The maximum distance is {maximum}")
