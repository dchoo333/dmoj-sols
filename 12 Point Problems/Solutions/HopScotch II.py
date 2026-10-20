from collections import deque

n, k = map(int, input().split())
a = [0] + list(map(int, input().split())) + [0]

p = [-1] * (n + 2)
q = deque([(0, 0)])

for i in range(1, n + 2):
    p[i] = q[0][0]
    c = q[0][1] + a[i]
    while q and q[-1][1] >= c:
        q.pop()
    q.append((i, c))
    if q[0][0] == i - k:
        q.popleft()

r = []
i = n + 1
while i:
    r.append(i)
    i = p[i]
r.pop(0)

print(q[-1][1])
print(*r[::-1])