t = int(input())
for k in range(t):
    n = int(input())
    m = tuple(tuple(int(input()) for _ in range(n)) for _ in range(n))
    s = sum(m[0])
    ok = all(sum(m[i][j] for j in range(n)) == s for i in range(n))
    print("yes" if ok else "no")
    if k < t - 1:
        input()
