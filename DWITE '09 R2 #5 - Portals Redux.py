from collections import deque

r = int(input())
c = int(input())
g = [input().ljust(c)[:c] for _ in range(r)]

p = {}
for i in range(r):
    for j in range(c):
        p[g[i][j]] = (i, j)

for s in '12345':
    f = []
    if s in p:
        v = [[0] * c for _ in range(r)]
        q = deque([p[s]])
        v[p[s][0]][p[s][1]] = 1
        while q:
            i, j = q.popleft()
            ch = g[i][j]
            if ch in '12345' and ch != s: f.append(ch)
            nb = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
            if 'a' <= ch <= 'j' and ch.upper() in p: nb.append(p[ch.upper()])
            for x, y in nb:
                if 0 <= x < r and 0 <= y < c and not v[x][y] and g[x][y] != '#':
                    v[x][y] = 1
                    q.append((x, y))
    print(s + ':' + ' '.join(sorted(f)))