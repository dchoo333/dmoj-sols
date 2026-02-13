n, t = map(int, input().split())
c = list(input())

while t > 0:
    p = 1
    while p * 2 <= t:
        p *= 2

    nxt = ['0'] * n

    for i in range(n):
        l = (i - p) % n
        r = (i + p) % n

        XOR = (1 if c[l] == '1' else 0) ^ (1 if c[r] == '1' else 0)

        nxt[i] = '1' if XOR == 1 else '0'

    c = nxt
    t -= p

print(''.join(c))