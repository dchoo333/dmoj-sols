n, q = map(int, input().split())
v = list(map(int, input().split()))

F = (1 << 32) - 1
sz = 1
while sz < n: sz <<= 1
t = [F] * (2 * sz)
t[sz:sz + n] = v
for i in range(sz - 1, 0, -1): t[i] = t[2 * i] & t[2 * i + 1]

o = []
for _ in range(q):
    s = input().split()
    if s[0] == 'U':
        i = int(s[1]) - 1 + sz
        t[i] = int(s[2])
        i >>= 1
        while i:
            t[i] = t[2 * i] & t[2 * i + 1]
            i >>= 1
    else:
        l = int(s[1]) - 1 + sz
        r = int(s[2]) + sz
        a = int(s[3])
        while l < r:
            if l & 1: a &= t[l]; l += 1
            if r & 1: r -= 1; a &= t[r]
            l >>= 1; r >>= 1
        o.append(a)

print("\n".join(map(str, o)))