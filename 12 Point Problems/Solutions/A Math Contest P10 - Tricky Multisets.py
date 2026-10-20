MOD = 10**9 + 7
inv2 = pow(2, MOD - 2, MOD)

N = int(input())
cts = list(map(int, input().split())) 
total = 0
for i, c in enumerate(cts):
    v = i - N
    if v != 0 and c != 0:
        total = (total + v * v % MOD * (c % MOD)) % MOD

print(total * inv2 % MOD)
