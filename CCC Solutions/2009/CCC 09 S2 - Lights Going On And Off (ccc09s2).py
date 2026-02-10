r, c = [int(input()) for _ in range(2)]
b = []

for _ in range(r):
    row = list(map(int, input().split()))
    n = 0
    for x in row:
        n = (n << 1) | x
    b.append(n)

p = set([b[0]])

for i in range(1, r):
    cset = set([b[i]])
    for x in p:
        cset.add(b[i] ^ x)
    p = set(cset)

print(len(p))
