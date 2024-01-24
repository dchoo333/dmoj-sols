arr = ["A", "B", "C", "D", "E"]
while True:
    first = int(input())
    second = int(input())
    if first == 4 and second == 1:
        break
    if first == 1:
        for i in range(second):
            temp = ""
            temp = arr[0]
            arr[0] = arr[1]
            arr[1] = arr[2]
            arr[2] = arr[3]
            arr[3] = arr[4]
            arr[4] = temp
    if first == 2:
        for i in range(second):
            temp = ""
            temp = arr[4]
            arr[4] = arr[3]
            arr[3] = arr[2]
            arr[2] = arr[1]
            arr[1] = arr[0]
            arr[0] = temp
    if first == 3:
        for i in range(second):
            temp = ""
            temp = arr[0]
            arr[0] = arr[1]
            arr[1] = temp
for i in range(5):
    print(arr[i], end=" ")