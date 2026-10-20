import sys
D = sys.stdin.buffer.read().split()
n = int(D[0])

H = []; C = []
a = 0
for i in range(1, n + 1):
    h = int(D[i])
    while H and H[-1] < h:
        a += C.pop(); H.pop()
    if H and H[-1] == h:
        c = C[-1]
        a += c + (len(H) > 1)
        C[-1] = c + 1
    else:
        if H: a += 1
        H.append(h); C.append(1)

print(a)