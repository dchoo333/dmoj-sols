def f(s):
    for i, c in enumerate(s):
        if c == ' ':
            return i + 1
    return 0

for _ in range(int(input())):
    print(f(input()))
