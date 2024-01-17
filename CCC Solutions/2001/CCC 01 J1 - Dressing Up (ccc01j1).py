n = int(input())
sort = []
for i in range(n):
  sort.append(i + 1)
sort = reversed(sort)
nums = []
for i in range(n):
  if (i + 1) % 2 == 1:
    if i+1 != n:
      nums.append(i+1)
    else:
      nums.append((i+1) * 2)
for i in sort:
  if (i - 1) % 2 == 1:
    if i-1 != n:
      nums.append(i-1)
    else:
      nums.append((i-1) * 2)
for num in nums:
  if num == n * 2:
    print('*' * n * 2)
  else:
    print('*' * num + ((n - num) * 2) * ' ' + '*' * num)

