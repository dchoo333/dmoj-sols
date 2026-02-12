from collections import deque

while True:
    n = int(input())
    if n == 0:
        break

    arr = list(map(int, input().split()))
    mask = sum(x << (3*(a-1)) for x,a in enumerate(arr))
    end = sum(x << (3*x) for x in range(n))

    vis = set()
    vis.add(mask)
    q = deque([mask])
    steps = 0
    found = False

    while q and not found:
        for _ in range(len(q)):
            node = q.popleft()
            if node == end:
                print(steps)
                found = True
                break

            top = [10]*n
            for i in range(n):
                pos = (node >> (3*i)) & 7
                top[pos] = min(top[pos], i)

            for i in range(n):
                pos = (node >> (3*i)) & 7
                if top[pos] != i:
                    continue

                for d in [-1, 1]:
                    np = pos + d
                    if 0 <= np < n and top[np] > i:
                        nn = node ^ ((pos ^ np) << (3*i))
                        if nn not in vis:
                            vis.add(nn)
                            q.append(nn)
        steps += 1

    if not found:
        print("IMPOSSIBLE")
