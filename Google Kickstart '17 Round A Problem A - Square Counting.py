for t in range(1, int(input()) + 1):
    r, c = map(int, input().split())
    n = min(r, c) - 1
    s1 = n * (n + 1) // 2
    s2 = n * (n + 1) * (2 * n + 1) // 6
    s3 = s1 * s1
    print(f"Case #{t}: {(r * c * s1 - (r + c) * s2 + s3) % (10**9 + 7)}")