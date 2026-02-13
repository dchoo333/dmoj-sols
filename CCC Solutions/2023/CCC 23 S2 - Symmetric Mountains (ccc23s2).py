N = int(input())
m = list(map(int, input().split()))

mins = [int(2e10)] * (N + 1)

for mid in range(N):
    l = r = mid
    size = 1
    asy = 0
    mins[size] = min(asy, mins[size])
    while l > 0 and r < N - 1:
        l -= 1
        r += 1
        size += 2
        asy += abs(m[l] - m[r])
        mins[size] = min(asy, mins[size])

m1, m2 = 0, 1
while m2 < N:
    l, r = m1, m2
    size = 2
    asy = abs(m[m1] - m[m2])
    mins[size] = min(asy, mins[size])
    while l > 0 and r < N - 1:
        l -= 1
        r += 1
        size += 2
        asy += abs(m[l] - m[r])
        mins[size] = min(asy, mins[size])
    m1 += 1
    m2 += 1

print(*mins[1:])
