t = int(input())
s = int(input())
h = int(input())
line = '*' * ((s * 2) + 3)
spaces = ' ' * (s + 1)
for i in range(t):
  print('*' + (' ' * s) + '*' + (' ' * s) + '*')
print(line)
for i in range(h):
  print(f"{spaces}*")
