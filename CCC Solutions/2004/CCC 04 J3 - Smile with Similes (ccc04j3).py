n, m = [int(input()) for _ in range(2)]
adjs = [input() for _ in range(n)]
nouns = [input() for _ in range(m)]

for a in adjs:
    for b in nouns:
        print(f'{a} as {b}')
