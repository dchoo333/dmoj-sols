a = int(input())
arr = []

for i in range(a):
    arr.append(int(input()))

t_values = [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000]

count = 10 - a

for i in range(a):
    t_dict = {1: 0, 2: 1, 3: 2, 4: 3, 5: 4, 6: 5, 7: 6, 8: 7, 9: 8, 10: 9}
    t_index = t_dict.get(arr[i])
    if t_index is not None:
        t_values[t_index] = 0

finalmoney = sum(t_values)
money = int(input())

if finalmoney / count < money:
    print("deal")  # YAY INFINITE MONEY GLITCH
else:
    print("no deal")  # NO DEAL YOU SCAMMER