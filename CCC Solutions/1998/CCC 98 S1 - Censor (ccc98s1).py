n = int(input())
for i in range(n):
    x = input()
    words = []
    for word in x.split():
        if len(word) == 4:
            words.append('****')
        else:
            words.append(word)
    print(' '.join(words))

