sq = 1
for i in range(1000000):
  n = int(input())
  if n == 0:
    print('You Quit!')
    break
  if sq + n == 100:
    print(f'You are now on square 100')
    print('You Win!')
    break
  elif sq + n > 100:
    print(f'You are now on square {sq}')
    sq = sq
  elif sq + n == 9:
    print(f'You are now on square 34')
    sq = 34
  elif sq + n == 54:
    print(f'You are now on square 19')
    sq = 19
  elif sq + n == 40:
    print(f'You are now on square 64')
    sq = 64
  elif sq + n == 90:
    print('You are now on square 48')
    sq = 48
  elif sq + n == 67:
    print('You are now on square 86')
    sq = 86
  elif sq + n == 99:
    print('You are now on square 77')
    sq = 77
  else:
    print(f'You are now on square {sq + n}')
    sq = sq + n