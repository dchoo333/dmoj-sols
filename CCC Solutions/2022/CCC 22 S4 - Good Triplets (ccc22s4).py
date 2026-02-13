n, c = map(int, input().split())
a = list(map(int, input().split()))

cnt = [0] * c
for x in a:
    cnt[x] += 1

s = [0] * c
s[0] = cnt[0]
for i in range(1, c):
    s[i] = s[i - 1] + cnt[i]

ans = n * (n - 1) * (n - 2) // 6

for i in range(c):
    o = (i + c // 2) % c
    if i + 1 <= o:
        b = s[o] - s[i]
    else:
        b = s[o] + s[c - 1] - s[i]

    ans -= cnt[i] * b * (b - 1) // 2
    ans -= cnt[i] * (cnt[i] - 1) * b // 2
    ans -= cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) // 6

if c % 2 == 0:
    for i in range(c // 2):
        o = i + c // 2
        ans += cnt[i] * (cnt[i] - 1) * cnt[o] // 2
        ans += cnt[i] * cnt[o] * (cnt[o] - 1) // 2

print(ans)
