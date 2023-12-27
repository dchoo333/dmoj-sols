def space(s):
    for i, char in enumerate(s):
        if char == ' ':
            return i + 1  
    return 0
T = int(input())
for _ in range(T):
    S = input()
    position = space(S)
    print(position)
