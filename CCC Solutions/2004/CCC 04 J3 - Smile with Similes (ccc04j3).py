n = int(input())
m = int(input())
adjectives = []
nouns = []
for i in range(n):
    adj = input()
    adjectives.append(adj)
for i in range(m):
    noun = input()
    nouns.append(noun)
for item in adjectives:
    for noun in nouns:
        print(f'{item} as {noun}')
