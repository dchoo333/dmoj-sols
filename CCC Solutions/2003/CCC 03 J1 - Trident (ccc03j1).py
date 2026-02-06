t, s, h = [int(input()) for _ in range(3)]
line = '*' * ((s * 2) + 3)
spaces = ' ' * (s + 1)
for i in range(t):
  print('*' + (' ' * s) + '*' + (' ' * s) + '*')
print(line)
for i in range(h):
  print(f"{spaces}*")