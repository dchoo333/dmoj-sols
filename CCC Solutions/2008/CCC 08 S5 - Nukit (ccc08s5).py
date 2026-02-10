n = int(input())
dp = {}

for _ in range(n):
    a, b, c, d = map(int, input().split())
    stack = [(a, b, c, d)]

    while stack:
        t = stack.pop()

        if t in dp:
            continue

        x, y, z, w = t
        ms = []

        if x >= 2 and y >= 1 and w >= 2:
            ms.append((x - 2, y - 1, z, w - 2))

        if x >= 1 and y >= 1 and z >= 1 and w >= 1:
            ms.append((x - 1, y - 1, z - 1, w - 1))

        if z >= 2 and w >= 1:
            ms.append((x, y, z - 2, w - 1))

        if y >= 3:
            ms.append((x, y - 3, z, w))

        if x >= 1 and w >= 1:
            ms.append((x - 1, y, z, w - 1))

        if not ms:
            dp[t] = False
        elif all(m in dp and dp[m] for m in ms):
            dp[t] = False
        elif any(m in dp and not dp[m] for m in ms):
            dp[t] = True
        else:
            stack.append(t)
            for m in ms:
                if m not in dp:
                    stack.append(m)
            continue

    print("Patrick" if dp[(a, b, c, d)] else "Roland")
