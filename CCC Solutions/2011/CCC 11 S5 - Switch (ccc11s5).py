from collections import deque

n = int(input())
mask = 0
for _ in range(n):
    mask = (mask << 1) | int(input())

vs = {mask}
queue = deque([(mask, 0)])

while queue:
    m, d = queue.popleft()
    if m == 0:
        print(d)
        break
    for k in range(n):
        if (m & (1 << k)) == 0 and ((k == 0 and (m & (1 << 1))) or
                                     (0 < k < n - 1 and ((m & (1 << (k - 1))) or (m & (1 << (k + 1))))) or
                                     (k == n - 1 and (m & (1 << (n - 2))))):
            new_m, cur, s = m | (1 << k), 0, 0
            for j in range(n + 1):
                if new_m & (1 << j):
                    cur += 1
                elif cur > 0:
                    if cur < 4:
                        s |= ((1 << cur) - 1) << (j - cur)
                    cur = 0
            if s not in vs:
                vs.add(s)
                queue.append((s, d + 1))
