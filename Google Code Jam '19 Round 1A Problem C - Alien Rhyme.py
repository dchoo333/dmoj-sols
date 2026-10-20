import sys
sys.setrecursionlimit(10000)

def solve(ws):
    ch = [{}]
    en = [0]
    for w in ws:
        x = 0
        for c in reversed(w):
            y = ch[x].get(c)
            if y is None:
                y = len(ch)
                ch[x][c] = y
                ch.append({})
                en.append(0)
            x = y
        en[x] += 1

    a = 0
    def dfs(x, r):
        nonlocal a
        c = en[x]
        for y in ch[x].values():
            c += dfs(y, False)
        if not r and c >= 2:
            a += 2
            c -= 2
        return c

    dfs(0, True)
    return a

t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    ws = []
    for _ in range(n):
        ws.append(input())
    print(f"Case #{tc}: {solve(ws)}")
