for _ in range(int(input())):
    n = int(input())
    steps = [input() for _ in range(n)]
    root = steps[-1]
    stack, m = [root], 0
    for s in steps:
        if s in stack: stack.pop()
        else: stack.append(s)
        m = max(m, len(stack))
    print(n*10 - 2*(m-1)*10)
