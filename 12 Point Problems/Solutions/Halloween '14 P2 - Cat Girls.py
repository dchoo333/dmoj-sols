from bisect import bisect_left

n, w = map(int, input().split())
P = [0] * (n + 1); C = [0] * (n + 1); B = [0] * (n + 1)
k = 0
o = []

for _ in range(n):
    s = input().split()
    if s[0] == 'D':
        k -= 1
        continue
    k += 1
    P[k] = P[k - 1] + int(s[1])
    C[k] = C[k - 1] + int(s[2])
    j = bisect_left(P, P[k] - w, 0, k + 1)
    B[k] = max(B[k - 1], C[k] - C[j])
    o.append(B[k])

print("\n".join(map(str, o)))