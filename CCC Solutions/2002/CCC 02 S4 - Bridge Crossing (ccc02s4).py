m = int(input())
n = int(input())

nm = [None]*n
t = [0]*n

for i in range(n):
    nm[i] = input()
    t[i] = int(input())

dp = [10**18]*(n+1)
gs = [0]*(n+1)
dp[0] = 0

for i in range(n):
    mx = 0
    di = dp[i]
    for j in range(1, m+1):
        k = i + j
        if k > n:
            break
        v = t[k-1]
        if v > mx:
            mx = v
        x = di + mx
        if x < dp[k]:
            dp[k] = x
            gs[k] = j

print(f"Total Time: {dp[n]}")

out = []
p = n
while p:
    out.append(gs[p])
    p -= gs[p]

i = 0
for s in reversed(out):
    print(" ".join(nm[i:i+s]))
    i += s
