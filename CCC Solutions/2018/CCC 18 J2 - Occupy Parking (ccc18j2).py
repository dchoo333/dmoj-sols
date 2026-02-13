n = int(input())
a, b = [input() for _ in range(2)]
count = 0
for i in range(n):
    if a[i] == b[i] == 'C':
        count = count + 1
print(count)