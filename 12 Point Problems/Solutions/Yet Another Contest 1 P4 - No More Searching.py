n = int(input())
s = input().strip()
w = [(ord(ch) - 64) ** 2 for ch in s]
O = 85176
H = n // 2 + 1

dp = [0] * (H + 2)
dp[0] = 1 << O
for i in range(n):
    x = w[i]
    lim = min(i + 1, n - i - 1, H)
    nd = [0] * (H + 2)
    for b in range(lim + 1):
        v = dp[b]
        if b >= 1: v |= dp[b - 1] << x
        v |= dp[b + 1] >> x
        nd[b] = v
    dp = nd

r = dp[0]
o = []
while r:
    lb = r & -r
    o.append(lb.bit_length() - 1 - O)
    r ^= lb

print(len(o))
print("\n".join(map(str, o)))